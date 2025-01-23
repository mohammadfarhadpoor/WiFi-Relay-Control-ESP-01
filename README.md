# WiFi-Relay-Control-ESP-01
### Explanation of the Code (English)

This code is designed for controlling a relay module via a web interface using the ESP8266 microcontroller. Here's how the code works:

1. **Wi-Fi Setup**:  
   The ESP8266 is configured as a Wi-Fi Access Point (AP) with a static IP address (`192.168.4.4`). Users can connect to this AP using the SSID (`Sigma Relay Controler`) and password (`sigmaelectronics.ir`).

2. **Server Initialization**:  
   An HTTP server is set up on port 80 to handle incoming client requests. The server will deliver an HTML page to the clients when accessed via a browser.

3. **HTML Content**:  
   The HTML code defines the structure of a web page that includes buttons to control the relay:
   - **LED ON Button**: Sends a request to turn the relay on.
   - **LED OFF Button**: Sends a request to turn the relay off.

4. **Relay Control**:  
   - When a client sends an HTTP request containing the action `PlugON`, the relay (connected to pin 2) is turned on by setting the pin to HIGH.
   - Similarly, for the action `PlugOFF`, the relay is turned off by setting the pin to LOW.

5. **Dynamic Response (Optional)**:  
   The commented-out section for `html_Plug` can dynamically display whether the relay is currently on or off. This feature can be activated if desired.

6. **Client Handling**:  
   - The code reads the HTTP request from the client.
   - Based on the request's content, the relay state is updated, and an appropriate HTML response is sent back to the client.

7. **Delay and Flush**:  
   After responding to the client's request, a small delay ensures the response is transmitted correctly, and the client buffer is cleared.

---

### توضیحات کد (فارسی)

این کد برای کنترل یک ماژول رله از طریق یک رابط وب با استفاده از میکروکنترلر ESP8266 طراحی شده است. عملکرد کد به صورت زیر است:

1. **تنظیمات Wi-Fi**:  
   ماژول ESP8266 به عنوان یک اکسس پوینت (AP) با آدرس IP ثابت (`192.168.4.4`) پیکربندی شده است. کاربران می‌توانند با استفاده از SSID (`Sigma Relay Controler`) و رمز عبور (`sigmaelectronics.ir`) به این شبکه متصل شوند.

2. **راه‌اندازی سرور**:  
   یک سرور HTTP بر روی پورت 80 راه‌اندازی شده است تا درخواست‌های کلاینت‌ها را مدیریت کند. وقتی کاربران از طریق مرورگر به آدرس AP دسترسی پیدا می‌کنند، صفحه HTML به آنها ارائه می‌شود.

3. **محتوای HTML**:  
   کد HTML ساختار صفحه وب را تعریف می‌کند که شامل دکمه‌هایی برای کنترل رله است:
   - **دکمه LED ON**: یک درخواست برای روشن کردن رله ارسال می‌کند.
   - **دکمه LED OFF**: یک درخواست برای خاموش کردن رله ارسال می‌کند.

4. **کنترل رله**:  
   - زمانی که کلاینت یک درخواست HTTP شامل دستور `PlugON` ارسال می‌کند، رله (متصل به پایه 2) با تنظیم پایه به حالت HIGH روشن می‌شود.
   - به همین ترتیب، برای دستور `PlugOFF`، رله با تنظیم پایه به حالت LOW خاموش می‌شود.

5. **پاسخ‌دهی دینامیک (اختیاری)**:  
   بخشی که به نام `html_Plug` کامنت شده است، می‌تواند به صورت دینامیک نشان دهد که آیا رله روشن یا خاموش است. این قابلیت در صورت نیاز می‌تواند فعال شود.

6. **مدیریت کلاینت‌ها**:  
   - کد درخواست HTTP را از کلاینت خوانده و پردازش می‌کند.
   - بر اساس محتوای درخواست، وضعیت رله به‌روزرسانی شده و یک پاسخ HTML مناسب به کلاینت ارسال می‌شود.

7. **تاخیر و پاک‌سازی**:  
   پس از پاسخ به درخواست کلاینت، یک تاخیر کوتاه برای اطمینان از ارسال صحیح پاسخ اعمال شده و بافر کلاینت پاک می‌شود. 

