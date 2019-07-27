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
		$num1 = $_POST["u_num"];
		$q = "select * from buy where num = '$num1'";
		$result = $db->query($q);
		
		if ($result->num_rows == 0) echo "<h3 align='center'>주문내역이 없습니다.<br><a href='index.html'>메인 메뉴로</a></h3>";
		else {
			$data = $result->fetch_row();
			echo "<br><br><br><p align='center'>주문번호 :" .$num1;
			echo "<br/><span>상품명 : </span>" .$data[1];
			echo "<br/><span>색상 : </span>" .$data[2];
			echo "<br/><span>갯수 : </span>" .$data[3];
			echo "<br/><span>가격 : </span>" .$data[4];
			echo "<br/><span>배송지 : </span>" .$data[5];
			echo "<br/><span>입금통장번호 : (하나) 620-228872-861</span>";
			echo "<br/><a href='index.html'>주문 확인 완료</a></p>";
		}	
		
	?>
	</body> 
</html>
