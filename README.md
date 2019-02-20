# IFTTT Webhooks plugin for KidBrightIDE

ปลั๊กอินเสริมส่งข้อมูลเข้า IFTTT Webhooks สำหรับบอร์ด KidBright เขียนโปรแกรมด้วย KidBrightIDE

## การติดตั้ง

ให้ดาวน์โหลดไฟล์เวอร์ชั่น Source Code มา แล้วแตกไฟล์ จะได้โฟลเดอร์ ifttt_webhooks ให้ย้ายโฟลเดอร์ ifttt_webhooks นี้ ไปไว้ในโฟลเดอร์ `[ไดร์ที่ติดตั้ง Windows]\Users\[Username]\AppData\Local\KidBright\app-[version]\resources\app\kbide\plugins` จากนั้นเปิดโปรแกรม KidBrightIDE ขึ้นมา บล็อกจะอยู่ในเมนู ปลั๊กอิน > IFTTT Webhooks

**กรณีใช้ KidBright IDE (64bits, New UI, Plugins beta version) ให้กดเมนู Plugins > Install Plagins แล้วเลือกไฟล์ .zip ได้เลย** 

## บล็อกที่มีให้ใช้งาน

### IFTTT Webhooks trigger

![TXC8M0.png](https://sv1.picz.in.th/images/2019/02/21/TXC8M0.png)

ใช้ส่ง trigger ไปยัง IFTTT Webhooks โดยค่า Value1 Value2 และ Value3 รองรับบล็อกชนิดข้อความ ตัวเลข และค่าจริง/เท็จ

## IFTTT คืออะไร

IFTTT เป็นบริการกลางที่จะช่วยส่งข้อมูลไปยังบริการต่าง ๆ เช่น ตั้งเวลาส่งการแจ้งเตือนไปทาง LINE, ตั้งเวลาเมื่อเช้าแล้วให้โพส Facebook, เมื่อโพสภาพ Facebook ไปแล้ว ให้ไปโพสลงใน Google Photo อัตโนมัติ เป็นต้น

## IFTTT Webhooks คืออะไร

IFTTT Webhooks เป็นบริการที่ให้อุปกรณ์ต่าง ๆ ส่งข้อมูลไปยัง IFTTT จากนั้น IFTTT จะส่งต่อข้อมูลเหล่านั้นไปยังบริการอื่น เช่น ต้องการให้อุปกรณ์ IoT โพสทวิตเตอร์ได้ เพื่อลดความยุ่งยากในการพัฒนาจึงเลือกใช้ IFTTT ภาพรวมขั้นตอนการทำงานให้อุปกรณ์ IoT โพสทวิตเตอร์ได้จึงมีดังนี้

 1. อุปกรณ์ส่งข้อมูลไปยัง IFTTT Webhooks ผ่านโปรโตคอล HTTP
 2. IFTTT Webhooks รับข้อมูลมา แล้วส่งข้อมูลต่อไปยังบริการทวิตเตอร์ที่อยู่ภายใน IFTTT เอง
 3. บริการทวิตเตอร์ของ IFTTT ส่งข้อมูลไปยังทวิตเตอร์
 4. ทวิตเตอร์ได้รับข้อมูล จึงทวิตข้อความให้

ข้อดีของ IFTTT Webhooks เป็นตัวกลาง และสามารถกำหนดให้ส่งข้อมูลต่อไปยังบริการใด ๆ ก็ได้ที่ IFTTT รองรับ เช่น

 1. Google Drive
 2. Google Sheets
 3. Google Doc
 4. Google Photos
 5. Facebook Pages
 6. Facebook Messenger
 7. Twitter
 8. WordPress
 9. ส่งอีเมล์
 10. โทรออก
 11. ส่ง SMS
 
ทั้งนี่แต่ละบริการที่ IFTTT รองรับ ยังมีบริการย่อยอีก เช่น

 * บริการ Google Drive รองรับการอัพโหลดไฟล์ภาพ เสียง วิดีโอ ผ่านลิ้ง
 * บริการ Google Photos รองรับการอัพโหลดรูปภาพผ่านลิ้ง สร้างอัลบั่ม
 * บริการ Google Sheets รองรับการเพิ่มข้อมูลในชีต รองรับการแก้ไขข้อมูลในชีต
 * บริการ Facebook Pages รองรับการโพส กด LINK

การเชื่อมโยงบริการต่าง ๆ สามารถทำได้โดยคลิกเพียงไม่กี่คลิกในเว็บของ IFTTT เอง

### ศัพท์ที่ควรรู้เมื่อใช้ IFTTT Webhooks

 * Event Name คือ ชื่อเหตุการณ์ที่ใช้ตอนเขียนโปรแกรม เพื่อบอกว่าให้ IFTTT ทำอะไร
 * Key คือ รหัสลับเฉพาะตัว ที่ใช้ตอนเขียนโปรแกรม
 * Value1, Value2, Value3 คือ ข้อมูลที่ IFTTT Webhooks เก็บไว้ สำหรับใช้ส่งต่อให้บริการอื่นต่อไป เช่น อุปกรณ์ IoT ต้องการโพส Facebook พร้อมแนบภาพประกอบ ที่อุปกรณ์ IoT จึงส่งข้อความที่โพสเข้ามาที่ Value1 และส่งลิ้งรูปภาพเข้ามาที่ Value2 เมื่อเชื่อมเข้ากับบริการ Facebook จึงเลือกว่าข้อความใช้ข้อมูลจาก Value1 และรูปภาพใช้ข้อมูลจาก Value2 เป็นต้น
   

## ตัวอย่าง: การส่งค่าอุณหภูมิจาก KidBright ไปเก็บใน Google Sheets ผ่าน IFTTT

การส่งข้อมูลไปยัง IFTTT นั้น ประกอบด้วย 2 ขั้นตอนหลัก ๆ คือ ตั้งค่าระบบของ IFTTT และเขียนโปรแกรมส่งข้อมูลไป IFTTT Webhooks

### ตั้งค่าระบบของ IFTTT

หัวข้อนี้เป็นการเตรียมระบบของ IFTTT ให้พร้อม โดยจะสั่งให้ IFTTT เชื่อมโยงบริการ IFTTT Webhooks เข้ากับ Google Sheets โดยเมื่อส่งข้อมูลเข้ามาที่ IFTTT Webhooks แล้ว ไฟล์ชีตที่อยู่ใน Google Drive จะมีแถวเพิ่มขึ้นมา

ให้สมัครสมาชิก IFTTT ให้เรียบร้อยที่ลิ้ง https://ifttt.com/discover โดยในเว็บเลือกได้ว่าจะสมัครโดยใช้บัญชี Google หรือ Facebook

เมื่อสมัครสมาชิกเรียบร้อยแล้ว ให้กดไปที่เมนู My Applets แล้วกดที่แท๊บ Applets

![TXPWBl.png](https://sv1.picz.in.th/images/2019/02/21/TXPWBl.png)

Applets คือการเชื่อมโยงบริการต่าง ๆ เข้าด้วยกัน เช่น เชื่อมบริการ Google Drive เข้ากับ Facebook จะเรียกว่า 1 Applet

การเชื่อมโยงบริการ หรือการสร้าง Applets ทำได้โดยกดที่ปุ่ม New Applet

![TXAIve.png](https://sv1.picz.in.th/images/2019/02/21/TXAIve.png)

ที่หน้า New Applet คลิกที่คำว่า +this เพื่อเลือกบริการแรกที่ต้องการเชื่อม

![TXPdqk.png](https://sv1.picz.in.th/images/2019/02/21/TXPdqk.png)

จากนั้นจะเข้าสู่หน้า Choose a service ซึ่งเป็นหน้าเลือกบริการแรกที่ต้องการเชื่อม ในตัวอย่างนี้จะเชื่อม IFTTT Webhooks เข้ากับ Google Sheets ดังนั้นบริการแรกคือ IFTTT Webhooks ในช่องค้นหาจึงพิมพ์ Webhooks แล้วกดเลือก Webhooks

![TXP08v.png](https://sv1.picz.in.th/images/2019/02/21/TXP08v.png)

แล้วจะแสดงบริการย่อยของ IFTTT Webhooks ขึ้นมา ให้กดเลือก Receive a web request (มีให้กดอันเดียว)

![TXPS7E.png](https://sv1.picz.in.th/images/2019/02/21/TXPS7E.png)

หน้า Complete trigger fields มีให้ตั้ง Event Name ซึ่งเปรียบเสมือนชื่อของการเชื่อมบริการครั้งนี้ และจะใช้อ้างอิงเมื่อเขียนโปรแกรม ตัวอย่างนี้จะตั้ง temp_log

![TXPYgN.png](https://sv1.picz.in.th/images/2019/02/21/TXPYgN.png)

ระบบจะพากลับมาหน้า New Applet แต่ครั้งนี้ให้คลิกที่ +that เพื่อกำหนดบริการตัวที่ 2

![TXPz2V.png](https://sv1.picz.in.th/images/2019/02/21/TXPz2V.png)

ที่หน้า Choose action service จะให้เลือกบริการตัวที่ 2 ในตัวอย่างนี้คือ Google Sheets จึงพิมพ์ลงช่องค้นหาว่า Google Sheets แล้วกดเลือก Google Sheets

![TXP4FQ.png](https://sv1.picz.in.th/images/2019/02/21/TXP4FQ.png)

ระบบจะพามาหน้าเลือกบริการย่อยของ Google Sheets ให้กดเลือก Add row to spreadsheet เนื่องจากจะให้บันทึกค่าอุณหภูมิลงใน Google Sheets อย่างต่อเนื่อง เพื่อให้นำมาทำเป็นกราฟได้

![TXPBtS.png](https://sv1.picz.in.th/images/2019/02/21/TXPBtS.png)

ในหน้ากำหนดค่าเฉพาะของบริการ สำหรับหรับ Google Sheets มีค่าให้กำหนดดังนี้

 * Spreadsheet name กำหนดชื่อไฟล์ชีต (ที่จะบันทึกลงใน Google Drive)
 * Formatted row รูปแบบการเพิ่มแถว - แถวที่เพิ่มประกอบด้วยหลายคอลั่ม การกำหนดให้แต่ละคอลั่มมีข้อมูลอะไรสามารถกำหนดได้จาก Formatted row นี้ ตัวอย่างต้องการให้คอลั่มแรกใส่ข้อมูลวันเวลาที่ส่งข้อมูลมา และคอลั่มที่สอง ใส่ข้อมูล Value1 ดังนั้นในช่อง Formatted row จึงใส่ {{OccurredAt}} ||| {{Value1}}
 * Drive folder path เลือกโฟลเดอร์เก็บไฟล์ชีต ตัวอย่างนี้เลือกเก็บไว้ที่ Temp log/outdoor
 
กำหนดค่าต่าง ๆ เสร็จแล้วให้กด Create action

![TXPfln.png](https://sv1.picz.in.th/images/2019/02/21/TXPfln.png)

หน้า Review and finish จะให้กำหนดข้อความที่ใช้อธิบาย Applet นี้ ในตัวอย่างกำหนดว่า "บันทึกค่าอุณหภูมิจาก KidBright ลง Google Sheets"

เมื่อกำหนดข้อความอธิบายแล้ว ให้กด Finish

![TXPhGg.png](https://sv1.picz.in.th/images/2019/02/21/TXPhGg.png)

ระบบจะพามาหน้ารายละเอียดของ Applet ที่สร้างขึ้น ให้กดที่ข้อความ Webhooks ที่มุมบนซ้ายของหน้าจอ หรือเข้าไปที่ลิ้ง https://ifttt.com/maker_webhooks

![TXP3fW.png](https://sv1.picz.in.th/images/2019/02/21/TXP3fW.png)

จากนั้น กดที่ปุ่ม Documentation 

![TXP9q2.png](https://sv1.picz.in.th/images/2019/02/21/TXP9q2.png)

หน้าใหม่จะเด้งขึ้นมา และแสดง key ขึ้นมา ให้เก็บค่า key ไว้ใช้ตอนเขียนโปรแกรม

![TXPTH1.png](https://sv1.picz.in.th/images/2019/02/21/TXPTH1.png)

ในหน้าที่เด้งมาใหม่นี้สามารถทดสอบการทำงานของ IFTTT Webhooks ได้ โดยกรอก Event Name ลงไป (ในตัวอย่างตอนกำหนด Event Name ตั้งไว้เป็น temp_log จึงกรอก temp_log) กรอกข้อมูบที่ต้องการส่งไปบันทึกใน Google Sheets ลงช่อง Value จากนั้นกดปุ่ม Test

![TXsdLf.png](https://sv1.picz.in.th/images/2019/02/21/TXsdLf.png)

จากนั้นข้อความ Event has been triggered. จะแสดงขึ้นมา เพื่อบอกว่าส่งข้อมูลไปยัง IFTTT Webhooks แล้ว

![TXs7ha.png](https://sv1.picz.in.th/images/2019/02/21/TXs7ha.png)

เมื่อเข้าไปใน Google Drive จะพบว่ามีไฟล์ชีตสร้างขึ้นมาใหม่ และในไฟล์ชีตนั้นมีข้อมูลที่ทดสอบส่งเพิ่มขึ้นมาแล้ว

![TXs4Y8.png](https://sv1.picz.in.th/images/2019/02/21/TXs4Y8.png)

### การเขียนโปรแกรม

ให้ติดตั้งปลั๊กอิน IFTTT Webhooks ลงโปรแกรม KidBrightIDE ให้เรียบร้อย จากนั้นให้ลากบล็อกออกมาต่อกันดังนี้

![TX2rTQ.png](https://sv1.picz.in.th/images/2019/02/21/TX2rTQ.png)

หลักการทำงานของโปรแกรมมีดังนี้

 * ใช้วนรอบเพื่อให้ส่งค่าอุณหภูมิไปบันทึกลง Google Sheets อย่างต่อเนื่อง
 * หน่วงเวลา 30 วินาที เพื่อกำหนดให้บันทึกค่าอุณหภูมิลง Google Sheets ทุก ๆ 30 วินาที
 * ใช้บล็อก IFTTT Webhooks trigger เพื่อส่งข้อมูลไปยัง IFTTT Webhook มีรายละเอียดดังนี้
   * ใช้บล็อกข้อความ มาต่อหลังคำว่า Key และใส่ค่า Key ของ IFTTT Webhooks ลงไป
   * ใช้บล็อกข้อความ มาต่อหลังคำว่า Event Name และใส่ค่า temp_log ลงไป (ในตัวอย่างตอนกำหนด Event Name ตั้งไว้เป็น temp_log)
   * ใช้บล็อกหัววัดอุณหภูมิ มาต่อหลังคำว่า Value1 เพื่อส่งค่าอุณหภูมิไปบันทึกลง Google Sheets
   * ใช้บล็อกข้อความ มาต่อหลังคำว่า Value2 โดยไม่ใส่ข้อความข้างใน เพราะตอนสร้าง Applet กำหนดค่าในบริการที่ 2 ไม่ได้ใช้ค่า Value2
   * ใช้บล็อกข้อความ มาต่อหลังคำว่า Value3 โดยไม่ใส่ข้อความข้างใน เพราะตอนสร้าง Applet กำหนดค่าในบริการที่ 2 ไม่ได้ใช้ค่า Value2

ตั้งค่าการเชื่อมต่อ WiFi (ไม่จำเป็นต้องเปิดใช้ IoT)

![TX26yV.png](https://sv1.picz.in.th/images/2019/02/21/TX26yV.png)

อัพโหลดโปรแกรมลงบอร์ด จากนั้นรอ 30 วินาที เมื่อครบแล้ว ข้อมูลอุณหภูมิที่วัดได้จะแสดงใน Google Sheets (กดสร้างแผนภูมิเพื่อสร้างกราฟได้)

![TXCFME.png](https://sv1.picz.in.th/images/2019/02/21/TXCFME.png)

**ข้อควรระวัง:** IFTTT จำกัดจำนวนครั้งในการส่งข้อมูลไปบันทึกใน Google Sheets เพื่อไม่ให้ถึงขีดจำกัดนั้น การส่งข้อมูลจึงไม่ควรถี่มากนัก ทั้งนี้หากข้อมูลไม่ถูกบันทึกอาจมีสาเหตุมาจากถึงขีดจำกัด ซึ่งสามารถดูได้ว่า IFTTT ถึงขีดจำกัดหรือยังโดยกดดูในเมนู Activity



