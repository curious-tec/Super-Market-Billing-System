Source code
1.	#include <iostream>
2.	#include<conio.h>
3.	#include<stdio.h>
4.	#include<process.h>
5.	#include<fstream>
6.	using namespace std;
7.	     class product
8.	    {
9.	        int pno;
10.	        char name[50];
11.	        float price, qty, tax, dis;
12.	        public:
13.	            void create_product()
14.	            {
15.	                cout << "\nPlease Enter The Product No. of The Product ";
16.	                cin >> pno;
17.	                cout << "\n\nPlease Enter The Name of The Product ";
18.	                cin>>gets(name);
19.	                cout << "\nPlease Enter The Price of The Product ";
20.	                cin >> price;
21.	                cout << "\nPlease Enter The Discount (%) ";
22.	                cin >> dis;
23.	            }
24.	        void show_product()
25.	        {
26.	            cout << "\nThe Product No. of The Product : " << pno;
27.	            cout << "\nThe Name of The Product : ";
28.	            puts(name);
29.	            cout << "\nThe Price of The Product : " << price;
30.	            cout << "\nDiscount : " << dis;
31.	        }
32.	        int retpno()
33.	        {
34.	            return pno;
35.	        }
36.	        float retprice()
37.	        {
38.	            return price;
39.	        }
40.	        char * retname()
41.	        {
42.	            return name;
43.	        }
44.	        int retdis()
45.	        {
46.	            return dis;
47.	        }
48.	    };
49.	fstream fp;
50.	product pr;
51.	void write_product()
52.	{
53.	    fp.open("Shop.dat", ios::out | ios::app);
54.	    pr.create_product();
55.	    fp.write((char * ) & pr, sizeof(product));
56.	    fp.close();
57.	    cout << "\n\nThe Product Has Been Created ";
58.	    getch();
59.	}
60.	void display_all()
61.	{
62.	    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
63.	    fp.open("Shop.dat", ios:: in );
64.	    while (fp.read((char * ) & pr, sizeof(product)))
65.	    {
66.	        pr.show_product();
67.	        cout << "\n\n====================================\n";
68.	        getch();
69.	    }
70.	    fp.close();
71.	    getch();
72.	}
73.	void display_sp(int n)
74.	{
75.	    int flag = 0;
76.	    fp.open("Shop.dat", ios:: in );
77.	    while (fp.read((char * ) & pr, sizeof(product)))
78.	    {
79.	        if (pr.retpno() == n)
80.	        {
81.	
82.	            pr.show_product();
83.	            flag = 1;
84.	        }
85.	    }
86.	    fp.close();
87.	    if (flag == 0)
88.	        cout << "\n\nrecord not exist";
89.	    getch();
90.	}
91.	
92.	void modify_product()
93.	{
94.	    int no, found = 0;
95.	    cout << "\n\n\tTo Modify ";
96.	    cout << "\n\n\tPlease Enter The Product No. of The Product";
97.	    cin >> no;
98.	    fp.open("Shop.dat", ios:: in | ios::out);
99.	    while (fp.read((char * ) & pr, sizeof(product)) && found == 0)
100.	    {
101.	        if (pr.retpno() == no)
102.	        {
103.	            pr.show_product();
104.	            cout << "\nPlease Enter The New Details of Product" << endl;
105.	            pr.create_product();
106.	            int pos = -1 * sizeof(pr);
107.	            fp.seekp(pos, ios::cur);
108.	            fp.write((char * ) & pr, sizeof(product));
109.	            cout << "\n\n\t Record Updated";
110.	            found = 1;
111.	        }
112.	    }
113.	    fp.close();
114.	    if (found == 0)
115.	        cout << "\n\n Record Not Found ";
116.	    getch();
117.	}
118.	void delete_product()
119.	{
120.	    int no;
121.	    cout << "\n\n\n\tDelete Record";
122.	    cout << "\n\nPlease Enter The product no. of The Product You Want To Delete";
123.	    cin >> no;
124.	    fp.open("Shop.dat", ios:: in | ios::out);
125.	    fstream fp2;
126.	    fp2.open("Temp.dat", ios::out);
127.	    fp.seekg(0, ios::beg);
128.	    while (fp.read((char * ) & pr, sizeof(product)))
129.	    {
130.	        if (pr.retpno() != no)
131.	        {
132.	            fp2.write((char * ) & pr, sizeof(product));
133.	        }
134.	    }
135.	    fp2.close();
136.	    fp.close();
137.	    remove("Shop.dat");
138.	    rename("Temp.dat", "Shop.dat");
139.	    cout << "\n\n\tRecord Deleted ..";
140.	    getch();
141.	}
142.	void menu()
143.	{
144.	
145.	    fp.open("Shop.dat", ios:: in );
146.	    if (!fp)
147.	    {
148.	        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
149.	
150.	        cout << "\n\n\n Program is closing ....";
151.	        getch();
152.	
153.	    }
154.	
155.	    cout << "\n\n\t\tProduct MENU\n\n";
156.	    cout << "====================================================\n";
157.	    cout << "P.NO.\t\tNAME\t\tPRICE\n";
158.	    cout << "====================================================\n";
159.	
160.	    while (fp.read((char * ) & pr, sizeof(product)))
161.	    {
162.	        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
163.	    }
164.	    fp.close();
165.	}
166.	void place_order()
167.	{
168.	    int order_arr[50], quan[50], c = 0;
169.	    float amt, damt, total = 0;
170.	    char ch = 'Y';
171.	    menu();
172.	    cout << "\n============================";
173.	    cout << "\n PLACE YOUR ORDER";
174.	    cout << "\n============================\n";
175.	    do
176.	    {
177.	        cout << "\n\nEnter The Product No. Of The Product : ";
178.	        cin >> order_arr[c];
179.	        cout << "\nQuantity in number : ";
180.	        cin >> quan[c];
181.	        c++;
182.	        cout << "\nDo You Want To Order Another Product ? (y/n)";
183.	        cin >> ch;
184.	    } while (ch == 'y' || ch == 'Y');
185.	    cout << "\n\nThank You For Placing The Order";
186.	    getch();
187.	
188.	    
189.	    cout << "\n\n******************************** INVOICE ************************\n";
190.	    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\ n ";
191.	
192.	    for (int x = 0; x <= c; x++)
193.	    {
194.	        fp.open("Shop.dat", ios:: in );
195.	        fp.read((char * ) & pr, sizeof(product));
196.	        while (!fp.eof())
197.	        {
198.	            if (pr.retpno() == order_arr[x])
199.	            {
200.	                amt = pr.retprice() * quan[x];
201.	                damt = amt - (amt * pr.retdis() / 100);
202.	                cout << "\n" << order_arr[x] << "\t" << pr.retname() <<
203.	                    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
204.	                total += damt;
205.	            }
206.	            fp.read((char * ) & pr, sizeof(product));
207.	        }
208.	
209.	        fp.close();
210.	        
211.	    }
212.	    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
213.	    getch();
214.	}
215.	void intro()
216.	{
217.	    cout <<endl<<endl <<"\tSUPER MARKET";
218.	    cout <<endl<<endl<< "\t\tBILLING";
219.	    cout <<endl<<endl<< "\t\t\tPROJECT";
220.	    cout << "\n\nMADE BY : chethan:pradeep:rizwan:reddy";
221.	   
222.	    cout << "\n\nWebsite : www.PuPapersBook.com";
223.	    getch();
224.	}
225.	void admin_menu()
226.	{
227.	    char ch2;
228.	    cout << "\n\n\n\tADMIN MENU";
229.	    cout << "\n\n\t1.CREATE PRODUCT";
230.	    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
231.	    cout << "\n\n\t3.QUERY ";
232.	    cout << "\n\n\t4.MODIFY PRODUCT";
233.	    cout << "\n\n\t5.DELETE PRODUCT";
234.	    cout << "\n\n\t6.VIEW PRODUCT MENU";
235.	    cout << "\n\n\t7.BACK TO MAIN MENU";
236.	    cout << "\n\n\tPlease Enter Your Choice (1-7) ";
237.	    ch2 = getche();
238.	    switch (ch2)
239.	    {
240.	    case '1':
241.	        write_product();
242.	        break;
243.	    case '2':
244.	        display_all();
245.	        break;
246.	    case '3':
247.	        int num;
248.	        cout << "\n\n\tPlease Enter The Product No. ";
249.	        cin >> num;
250.	        display_sp(num);
251.	        break;
252.	    case '4':
253.	        modify_product();
254.	        break;
255.	    case '5':
256.	        delete_product();
257.	        break;
258.	    case '6':
259.	        menu();
260.	        getch();
261.	    case '7':
262.	        break;
263.	    default:
264.	        cout << "\a";
265.	        admin_menu();
266.	    }
267.	}
268.	int main()
269.	{
270.	    char ch;
271.	    intro();
272.	    do
273.	    {
274.	
275.	        cout << "\n\n\n\tMAIN MENU";
276.	        cout << "\n\n\t01. CUSTOMER";
277.	        cout << "\n\n\t02. ADMINISTRATOR";
278.	        cout << "\n\n\t03. EXIT";
279.	        cout << "\n\n\tPlease Select Your Option (1-3) ";
280.	        ch = getche();
281.	        switch (ch)
282.	        {
283.	        case '1':
284.	
285.	            place_order();
286.	            getch();
287.	            break;
288.	        case '2':
289.	            admin_menu();
290.	            break;
291.	        case '3':
292.	            return 0 ;
293.	        default:
294.	            cout << "\a";
295.	        }
296.	    } while (ch != '3');
297.	}
