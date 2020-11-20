from django.test import TestCase
from django.test import Client
from LegacySite.models import User, Product, Card

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
