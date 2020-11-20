from django.test import TestCase
from django.test import Client
from LegacySite.models import User, Product, Card
from LegacySite.extras import parse_card_data

# Create your tests here.

class CSRFTestClass(TestCase):
  def setUp(self):
    u = User(username='test2', password="XXXXXXX")
    p = Product(product_id = 1, product_name = "test", product_image_path = "/images/null", recommended_price = 200, description = "test product")
    p.save()
    u.save()

  def test_csrf(self):
    #Initialize client with CSRF checks
    csrf_client = Client(enforce_csrf_checks=True)
    #Make the POST request that are our weaponized link triggers 
    response = csrf_client.post('/gift/1', {'amount':'2000','username':'test2'})
    self.assertEqual(response.status_code,403)

class XSSTestClass(TestCase):
  def setUp(self):
    p = Product(product_id = 1, product_name = "test", product_image_path = "/images/null", recommended_price = 200, description = "test product")
    p.save()

  def test_xss(self):
    #Initialize client with CSRF checks
    c = Client()
    failed=0
    #Make the GET request with XSS payload
    r1 = c.get('/gift/1', {'director':'<script>alert(1)</script>'})
    r2 = c.get('/buy',{'director':'<script>alert(1)</script>'}) 
    #Check if the string was escaped
    self.assertContains(r1,b"Endorsed by &lt;script&gt;alert(1)&lt;/script&gt;")
    self.assertContains(r2,b"Endorsed by &lt;script&gt;alert(1)&lt;/script&gt;")

class SQLITestClass(TestCase):
  def setUp(self):
    u = User(username='test2', password="000000000000000000000000000078d2$1591b96f209a6ed62b2d140f3a8087850a0c4799ae8f9fa3177adc58d9e091b0")
    p = Product(product_id = 1, product_name = "test", product_image_path = "/images/null", recommended_price = 200, description = "test product")
    c = Card(data=b"test signature", fp="/tmp/notreal", user=u, used=True, amount=200, product=p)
    p.save()
    u.save()
    c.save()

  def test_sqli(self):
    #Initialize client with CSRF checks
    c = Client()
    c.login(username='test2', password="test1")
    #Make the POST with SQLi in signature field of file 
    with open('./sqli_payload.json') as f:
      response = c.post('/use.html', {'card_fname':'test_file','card_supplied':'True','card_data':f})
    self.assertNotContains(response,b"000000000000000000000000000078d2$1591b96f209a6ed62b2d140f3a8087850a0c4799ae8f9fa3177adc58d9e091b0")


class CommandInjectionTestClass(TestCase):
  def test_commandinjection(self):
    tmp_file = parse_card_data(b"not json","test; ls -L1 LegacySite | sort | tee tmp_file#")
    output = ["admin.py","apps.py","extras.py"]
    #Check for three of the python scripts in LegacySite - alert if any are present in output  
    all(self.assertNotIn(tmp,tmp_file) for tmp in output)

