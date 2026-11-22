; func _apmngr_online_model_data_cmp @ 0x0054b2c4 size=0x30
  54b2c4:	27bdffe0 	addiu	sp,sp,-32
  54b2c8:	00001021 	move	v0,zero
  54b2cc:	10800006 	beqz	a0,0x54b2e8
  54b2d0:	afbf001c 	sw	ra,28(sp)
  54b2d4:	10a00005 	beqz	a1,0x54b2ec
  54b2d8:	8fbf001c 	lw	ra,28(sp)
  54b2dc:	0c101e4c 	jal	0x407930
  54b2e0:	24060018 	li	a2,24
  54b2e4:	2c420001 	sltiu	v0,v0,1
  54b2e8:	8fbf001c 	lw	ra,28(sp)
  54b2ec:	03e00008 	jr	ra
  54b2f0:	27bd0020 	addiu	sp,sp,32
