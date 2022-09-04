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

ערכי הknn מאותחלים להיות k=5 ופונקציית המרחק האוקלידית (EUC) אך ניתנים לשינוי כפי שנדרש בפקודה 2.


# מבנה הקוד
הקוד שלנו מורכב מכמה תיקיות אשר אחראיות על דברים שונים ובנוסף מכמה קבצים אחרים.
תיקיית הCommands אחראית על הפקודות שהשרת מסוגל לבצע כאשר התוכנית משתמשת בתבנית עיצוב Pattern Command כפי שהתבקשנו, כלומר לכל פקודה יש מחלקה האחראית על תפקודה וכולן יורשות ממחלקת האב האבסטרקטית Command.
בנוסף יש בתיקייה זו את מחלקת CLI שאחראית על הרצת הפקודות בהתאם לבחירות הלקוח.

תיקיית הIOs אחראית על הקלט-פלט כאשר בפועל בדרישות התרגיל דרוש שימוש רק בSocketIO אך הקוד מותאם גם לשימוש בStandardIO.
על ידי ירישה ממחלקה אבסטרקטית DefaultIO אנחנו מאפשרים את שני סוגי התקשורת כמעט ללא שינויים (כיוון שלא נדרש לא בדקנו עד הסוף את תפקוד הStandardIO אך ההתאמה שלו לקוד אמורה להיות פשוטה משום שהשימוש בפלט-קלט מחוץ למחלקות מתבצע רק באמצעות הDefaultIO אשר גם היא מממשת).

תיקיית הGenerals היא של הקבצים המוכרים לנו מהתרגילים הקודמים לעבודה עם קבצים ועם מחלקת האירוסים.

בנוסף מחוץ לתיקיות אלו יש לנו קבצי cpp וhpp עבור הלקוח והשרת.

server:
הסרבר יוצר סוקט ולאחר היצירה נותן 20 שניות ללקוחות להתחבר, במידה ולקוח מתחבר השרת יוצר עבורו thread עם CLI (כדי שירוץ במקביל) ומריץ בדו שיח עם הלקוח את הפקודות שהלקוח דורש.
לאחר כל חיבור של לקוח השרת מתחיל לספור 20 שניות מחדש (עד חיבור של חמישה לקוחות או שעובר הזמן).

client:
הלקוח יוצר סוקט ומתחבר לשרת ובתוכו שמור לו מה לעשות עבור כל פקודה שמתקבלת (כלומר איך לנהל את הדו-שיח עם השרת).

# מקביליות
ראשית כפי שהזכרנו קודם השרת יפעיל את הלקוחות במקביל ובנוסף בכתיבה לקובץ השרת יעשה זאת במקביל להמשך שיחה עם הלקוח על מנת שהלקוח לא יצטרך לחכות.

# דגשים להרצה
עבור הפקודה השנייה המכניסה פרמטרים עבור אלגוריתם הknn החלטנו מטעמי אסתטיקה ומשמעות שהמשתמש יצטרך להכניס ערך k ורק לאחר מכן את שם פוקנציית המטריקה על מנת למקד את הטעות במידה והערכים שהוכנסו לא נכונים ולכן לא ניתן להמשיך.

בשביל להפעיל את פקודות 3,6 המשתמש מוכרח להפעיל קודם את פקודה 1 משום שבפקודות 3 ו6 השרת דורש קבצים בכדי לבצע את הפקודות, ובשביל פקודות 4 ו5 המשתמש מוכרח להפעיל קודם את פקודה 3 על מנת שיהיה את האירוסים המסווגים עבור הדפסה/הורדה.


# פקודות קמפול והרצה

ראשית ניכנס באמצעות פקודות cd אל תיקיות עד שנגיע לתיקייה בה שמור הפרוייקט בכל החלונות (גם עבור השרת וגם עבור הלקוחות).

כעת בכדי לקמפל את השרת נכתוב:

g++ -std=c++11 -pthreads Commands/*.cpp IOs/*.cpp Generals/*.cpp server.cpp -o server.out

ובכדי לקמפל את הלקוחות נכתוב:

g++ -std=c++11 client.cpp -o client.out

עבור כל אחד בחלון המיועד עבורו.

בכדי להריצם נכתוב בחלון שלהם:

./server.out

עבור הסרבר שנריץ ראשון ו

./client.out

עבור הלקוחות.

לא צריך לקמפל מחדש עבור כל לקוח אלא מספיק כאשר נמצאים בתיקייה בה נמצא הפרוייקט להריץ את הקובץ המקומפל עבור הלקוח הראשון.

הרצת כל לקוח תהיה בחלון נפרד ולאחר התחברות כל לקוח יהיו 20 שניות מההתחברות ללקוחות אחרים להתחבר (עד חמישה) ולאחר מכן האופציה ללקוחות להתחבר תיסגר.
