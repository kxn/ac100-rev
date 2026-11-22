; func _wserv_is_rd_enable @ 0x005ea17c size=0x20
  5ea17c:	27bdffe0 	addiu	sp,sp,-32
  5ea180:	afbf001c 	sw	ra,28(sp)
  5ea184:	0c1874cc 	jal	0x61d330
  5ea188:	00000000 	nop
  5ea18c:	8fbf001c 	lw	ra,28(sp)
  5ea190:	0002102b 	sltu	v0,zero,v0
  5ea194:	03e00008 	jr	ra
  5ea198:	27bd0020 	addiu	sp,sp,32
