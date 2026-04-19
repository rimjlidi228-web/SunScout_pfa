**🌞 SunScout — Smart Solar Tracking System**
**📌 Description**

SunScout est un système IoT intelligent de suivi solaire basé sur ESP32.
Il permet d’optimiser la production d’énergie solaire en orientant automatiquement un panneau vers la source lumineuse la plus intense.

Le système combine capteurs, actionneur et interface web de supervision en temps réel.

**🎯 Objectifs**
Optimiser le rendement des panneaux solaires ☀️
Automatiser le suivi solaire 🤖
Fournir une supervision en temps réel 🌐
Réaliser une solution IoT simple et économique ⚙️
**🧱 Architecture du système**
|Couche	| Composants	|Rôle|
|-------|-------------|----|
|Capteurs|2× LDR GL5528|	Mesure lumière|
|Logique	|ESP32	|Traitement + décision|
|Actionneur	|Servo SG90	|Orientation panneau|
|Interface	|Web (HTML/CSS/JS)|Dashboard|

**🔧 Matériel utilisé**
|Composant |Référence|
|----------|---------|
|ESP32	|ESP32-WROOM-32|
|LDR	|GL5528|
|Servo	|SG90|
|Batterie|	18650|
|Charge	|TP4056|
|Panneau solaire|	5V 1W/2W|
|LED	|5mm + 220Ω|

**💻 Logiciels utilisés**
Arduino IDE 2.x
Visual Studio Code
Wokwi Simulator
Bibliothèques ESP32 (WiFi, WebServer, ESP32Servo)

**⚙️ Paramètres système**
| Paramètre | Valeur | Description |
|-----------|--------|-------------|
|threshold |200	|Sensibilité mouvement|
|speedStep	|2°|	Pas de rotation servo|
|loop delay	|80 ms|	Fréquence mise à jour|
**🌐 API REST**
Endpoint :
GET /data
Exemple réponse :
{
  "left": 2800,
  "right": 2100,
  "angle": 95,
  "led": true
}
**🧠 Fonctionnement**
1-Les LDR mesurent la lumière
2-ESP32 compare gauche/droite
3-Le servo s’oriente vers la lumière forte
4-Les données sont envoyées au dashboard
5-L’utilisateur visualise en temps réel
**🖥️ Interface Web**
Affichage capteurs LDR
Position du panneau
Graphiques temps réel
Historique des mouvements
Indicateur jour/nuit
LED virtuelle
**⚠️ Problèmes rencontrés**
Instabilité WiFi → reconnexion automatique
Déséquilibre capteurs → calibration + threshold
Oscillation servo → speedStep réduit
Bruit des capteurs → filtrage logiciel
**🚀 Améliorations futures**
Suivi solaire biaxial
WebSockets (temps réel)
Cloud IoT (MQTT / AWS)
Mesure énergie (INA219)
Mode économie énergie (deep sleep ESP32)
**👨‍💻 Équipe**
Farah Benarbi
Amani Arouri
Rym jlidi
Baraa Benarfi
Mohamed El Mehdi Aouni
🎓 Contexte académique

Projet réalisé à la Faculté des Sciences de Tunis (FST)
Licence LCE2 — IoT & Systèmes embarqués
Année universitaire : 2025/2026
