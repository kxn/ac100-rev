; func apmngr_db_is_pack_cfg_changed @ 0x005414cc size=0x34
  5414cc:	27bdffe0 	addiu	sp,sp,-32
  5414d0:	00001021 	move	v0,zero
  5414d4:	10800007 	beqz	a0,0x5414f4
  5414d8:	afbf001c 	sw	ra,28(sp)
  5414dc:	10a00005 	beqz	a1,0x5414f4
  5414e0:	248400a8 	addiu	a0,a0,168
  5414e4:	24a500a8 	addiu	a1,a1,168
  5414e8:	0c101e4c 	jal	0x407930
  5414ec:	240600d0 	li	a2,208
  5414f0:	0002102b 	sltu	v0,zero,v0
  5414f4:	8fbf001c 	lw	ra,28(sp)
  5414f8:	03e00008 	jr	ra
  5414fc:	27bd0020 	addiu	sp,sp,32
