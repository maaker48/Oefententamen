# Welcome to [SQL](https://github.com/maaker48/Oefententamen/blob/master/SQL.md)  

<details> 
  <summary>- In the entry field, select all customers the company currently delivers to.</summary>
   <p> A1: JavaScript </p> 
</details>

- In the entry field, select all customers the company currently delivers to.
    - SELECT * FROM Customers;

- Select all customers from Germany, but only their `CustomerName` and `City`
	- SELECT CustomerName, City
	FROM Customers;


- Select _Die Wandernde Kuh_ by using their `CustomerID`(id=86)
    - SELECT * 
    FROM Customers
    WHERE CustomerID =86;


- Select all customers _except_ those residing in Germany.
    - SELECT * FROM Customers WHERE Country<>'Germany';
    - SELECT * FROM Customers WHERE NOT Country ='Germany';
    

Due to a special event, all customers in either London or Madrid get a discount on their deliveries.

- Select all customers that are eligible for this discount with one statement
    - SELECT * FROM Customers WHERE City ='London' OR City='Madrid';

Customers from the USA pay extra because, well, it's the USA.

- Select all `CustomerID`s that pay the _regular_ shipping fee.
    - SELECT CustomerID FROM Customers WHERE Country<>'USA';
    - SELECT CustomerID FROM Customers WHERE NOT Country='USA';

Now that selection seems to work fine, we try to register some new clients.

- Add a new customer to the database (e.g. Minor Programming, or yourself)
    - INSERT INTO Customers (CustomerName, City, Country) VALUES ('Minor Programming', 'Uva', 'Sciencepark');
    - This will output INSERT INTO Customers (CustomerName, City, Country) VALUES ('Minor Programming', 'Uva', 'Sciencepark');

> What happens if you forget to insert data for a specific column?
 - see above^

Suppose a customer moves, and changes their address on our website. This should execute an SQL command which changes the customers address in the database.

- Change the address of our contact _Thomas Hardy_ to the next street over, 22 Maddox St.
    - UPDATE Customers SET Address='22 Maddox St.' WHERE ContactName='Thomas Hardy';

Whelp, due to the Brexit the UK population has decided they want their capital no longer be associated with present affairs and rename it as the Romans once called it, _Londinium_.

- Change all entries of London to the new name
    - UPDATE Customers SET City='Londinium' WHERE City='London';

- Change all contacts in London to 'Julius Caesar'
    UPDATE Customers SET ContactName='Julius Caesar' WHERE City='Londinium';

Due to political reasons, your company no longer affiliates with France (je ne comprend pas?).

- Remove all entries of French customers
    - DELETE FROM Customers Where Country='France';

Let's move on to our Products database.

- List all products currently in stock
    -SELECT * FROM Products;

- Count the number of products in stock (with a statement, we know you can count)
    - SELECT COUNT(Unit) FROM Products;

- Find the average price of all products
    - SELECT AVG(Price) FROM Products;

- Find the maximum price of all products
    - SELECT MAX(Price) FROM Products;

Someone ordered all products of 'Chef Anton'. We can select those easily with one statement.  

    SELECT * FROM Products WHERE ProductName LIKE '%Chef Anton%'; 

- Select all products with 'Chef Anton' but only show their prices  


    SELECT ProductName, Price FROM Products WHERE ProductName LIKE '%Chef Anton%'; 

## Exploits of a mom

With everything looking good, take a look at the following [xkcd](https://xkcd.com/) comic.

![Exploits of a mom](https://imgs.xkcd.com/comics/exploits_of_a_mom.png)

> Explain why this is funny.
- This is because it is an SQL injection To Drop The whole database

> Explain what the school should have done in order to prevent this.
- it sould define Value see below
        SELECT cash
        FROM users
        WHERE Name = :name,
        name="Robert;
