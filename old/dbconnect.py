# Verbindung zur Datenbank herstellen
try:
    connection = mysql.connector.connect(
        host="169.254.12.204",       # Hostname oder IP-Adresse des MySQL-Servers
        user="Transportrobot",    # Ihr MySQL-Benutzername
        password="12345",    # Ihr MySQL-Passwort
        database="transportroboterdb"    # Name Ihrer MySQL-Datenbank
    )

    if connection.is_connected():
        print("Verbindung zur MySQL-Datenbank hergestellt")

    # Hier können Sie Datenbankabfragen ausführen
    # Zum Beispiel:
    cursor = connection.cursor()
    cursor.execute("SELECT * FROM warenregal")
    results = cursor.fetchall()

    for row in results:
        print(row)

except mysql.connector.Error as err:
    print(f"Fehler: {err}")

finally:
    if 'connection' in locals() and connection.is_connected():
        cursor.close()
        connection.close()
        print("Verbindung zur MySQL-Datenbank geschlossen")
