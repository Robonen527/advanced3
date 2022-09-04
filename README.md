# Advanced-Programming-last-part

# השלב השלישי והאחרון של הפרוייקט בקורס תכנות מתקדם
בחלק זה של הפרוייקט המשכנו את הפרוייקט המתמשך שהתחלנו בתרגילים 1 ו2 ופיתחנו
מגוון רחב יותר של יכולות עבור השרת.
בכדי ליצור תקשורת בין הלקוחות לשרת השתמשנו בsockets בשיטת הTCP.
בנוסף השתמשנו בthreads בשביל לאפשר מקביליות כלומר יכולת של כמה חלקים בקוד לרוץ במקביל.
גודל הבאפר שבחרנו הוא 4096, חזקה של 2 וגודל הבאפר שחמי המליץ.
מספר הport שבחרנו הוא 5555 כיוון שהמספר יפה וזהו המספר שחמי נתן בדוגמה.
הגדרנו את משך הזמן בו השרת עדיין מסכים לקבל לקוחות להיות 20 שניות לאחר שהלקוח האחרון התחבר(או 20 שניות מתחילת ההרצה עבור הלקוח הראשון).
כלומר הtimeout הוא 20 שניות.
לאחר 20 שניות השרת ידפיס הודעה שאינו מוכן לקבל לקוחות ולא יהיה ניתן להתחבר אליו יותר.
השרת יוכל להאזין לעד חמישה לקוחות.


# מבנה הקוד
הקוד שלנו מורכב מכמה תיקיות אשר אחראיות על דברים שונים ובנוסף מכמה קבצים אחרים.
תיקיית הCommands אחראית על הפקודות
# פקודות קמפול
במידה ונרצה לשנות מן קובץ המידע המסווג הנתון הרגיל נוכל להחליף את הpath במקום המיועד לכך (שורה 15 בקובץ הserver).
בכדי לקמפל את הפרוייקט נריץ בשני חלונות נפרדים אחד עבור השרת ואחד עבור הלקוח.

ראשית ניכנס באמצעות פקודות cd אל תיקיות עד שנגיע לתיקייה בה שמור הפרוייקט בשני החלונות (גם עבור השרת וגם עבור הלקוח).
כעת בכדי לקמפל את השרת נכתוב:
g++ -std=c++11 server.cpp FilesFunc.cpp Iris.cpp -o server.exe
ובכדי לקמפל את הלקוח נכתוב:
g++ -std=c++11 client.cpp FilesFunc.cpp Iris.cpp -o client.exe
עבור כל אחד בחלון המיועד עבורו.

בכדי להריצם נכתוב בחלון שלהם:
./server.exe
עבור הסרבר שנריץ ראשון ו
./client.exe
עבור הלקוח.
לאחר מכן נקבל בקובץ אותו הכנסנו כקובץ Output את הסיווג שדרשנו.
