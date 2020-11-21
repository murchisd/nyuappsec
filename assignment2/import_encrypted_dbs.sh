echo -n "Password: "
read -s password

sqlcipher db_encrypted.sqlite3 << END_COMMANDS
PRAGMA key = '$password';
.mode csv
.import products.csv LegacySite_product
.import users.csv LegacySite_user
.exit
END_COMMANDS
