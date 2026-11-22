; func _wsta_ipv6_key @ 0x0063754c size=0x34
  63754c:	27bdffc8 	addiu	sp,sp,-56
  637550:	00802821 	move	a1,a0
  637554:	24060014 	li	a2,20
  637558:	afbf0034 	sw	ra,52(sp)
  63755c:	0c101c8c 	jal	0x407230
  637560:	27a40018 	addiu	a0,sp,24
  637564:	27a40018 	addiu	a0,sp,24
  637568:	24050014 	li	a1,20
  63756c:	0c1020f4 	jal	0x4083d0
  637570:	00003021 	move	a2,zero
  637574:	8fbf0034 	lw	ra,52(sp)
  637578:	03e00008 	jr	ra
  63757c:	27bd0038 	addiu	sp,sp,56
