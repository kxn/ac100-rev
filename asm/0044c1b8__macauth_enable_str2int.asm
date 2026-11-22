; func _macauth_enable_str2int @ 0x0044c1b8 size=0x24
  44c1b8:	3c05006e 	lui	a1,0x6e
  44c1bc:	27bdffe0 	addiu	sp,sp,-32
  44c1c0:	afbf001c 	sw	ra,28(sp)
  44c1c4:	0c101f44 	jal	0x407d10
  44c1c8:	24a59470 	addiu	a1,a1,-27536
  44c1cc:	8fbf001c 	lw	ra,28(sp)
  44c1d0:	2c420001 	sltiu	v0,v0,1
  44c1d4:	03e00008 	jr	ra
  44c1d8:	27bd0020 	addiu	sp,sp,32
