; func wserv_db_sync_wlan_to_re @ 0x005efe90 size=0x30
  5efe90:	27bdffe0 	addiu	sp,sp,-32
  5efe94:	3c06005f 	lui	a2,0x5f
  5efe98:	00803821 	move	a3,a0
  5efe9c:	afbf001c 	sw	ra,28(sp)
  5efea0:	00002821 	move	a1,zero
  5efea4:	94840000 	lhu	a0,0(a0)
  5efea8:	0c12de5f 	jal	0x4b797c
  5efeac:	24c60f7c 	addiu	a2,a2,3964
  5efeb0:	00001021 	move	v0,zero
  5efeb4:	8fbf001c 	lw	ra,28(sp)
  5efeb8:	03e00008 	jr	ra
  5efebc:	27bd0020 	addiu	sp,sp,32
