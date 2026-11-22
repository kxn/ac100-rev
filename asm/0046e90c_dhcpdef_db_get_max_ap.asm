; func dhcpdef_db_get_max_ap @ 0x0046e90c size=0x2c
  46e90c:	27bdffe0 	addiu	sp,sp,-32
  46e910:	afbf001c 	sw	ra,28(sp)
  46e914:	0c1506a9 	jal	0x541aa4
  46e918:	afb00018 	sw	s0,24(sp)
  46e91c:	0c1506b2 	jal	0x541ac8
  46e920:	00408021 	move	s0,v0
  46e924:	8fbf001c 	lw	ra,28(sp)
  46e928:	02021021 	addu	v0,s0,v0
  46e92c:	8fb00018 	lw	s0,24(sp)
  46e930:	03e00008 	jr	ra
  46e934:	27bd0020 	addiu	sp,sp,32
