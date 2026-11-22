; func _ap_union_cmp @ 0x00486174 size=0x30
  486174:	27bdffe0 	addiu	sp,sp,-32
  486178:	00001021 	move	v0,zero
  48617c:	10800006 	beqz	a0,0x486198
  486180:	afbf001c 	sw	ra,28(sp)
  486184:	10a00005 	beqz	a1,0x48619c
  486188:	8fbf001c 	lw	ra,28(sp)
  48618c:	0c101e4c 	jal	0x407930
  486190:	24060006 	li	a2,6
  486194:	2c420001 	sltiu	v0,v0,1
  486198:	8fbf001c 	lw	ra,28(sp)
  48619c:	03e00008 	jr	ra
  4861a0:	27bd0020 	addiu	sp,sp,32
