<!DOCTYPE HTML>
<html>
	<head>
		<meta charset="UTF-8"/>
	</head>
	<body>
	<?php
		$db = new mysqli("localhost", "samho101", "samho101108", "samho101");   
		if (mysqli_connect_errno()) {
			print "Error: Could not connect to database server.";
			exit;
		}   
		mysqli_set_charset($db, "utf8");
		
		$num = $_POST["u_num"];
		$name = $_POST["u_name"];
		$color = $_POST["u_color"];
		$price = $_POST["u_price"];
		$count = $_POST["u_count"];
		$address = $_POST["u_address"];
		
		$q = "insert into buy (num, name, color, price, count, address) values ('$num', '$name', '$color', '$price', '$count', '$address')";      
		$result = $db->query($q);
		
		echo "<br><br><br><p align='center' >주문이 완료 되었습니다.";
		echo "<br/><span>주문번호: </span>" .$num;
		echo "<br/><span>상품명: </span>" .$name;
		echo "<br/><span>색상: </span>" .$color;
		echo "<br/><span>갯수: </span>" .$count;
		echo "<br/><span>가격: </span>" .$price;
		echo "<br/><span>배송지: </span>" .$address;
		echo "<br/><a href='index.html'>주문확인</a></p>" ;		
	?>
	</body> 
</html>
