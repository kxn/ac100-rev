; func send_tdcp_request_to_ap @ 0x0050e2c0 size=0x44
  50e2c0:	27bdffc8 	addiu	sp,sp,-56
  50e2c4:	8fa20048 	lw	v0,72(sp)
  50e2c8:	10400002 	beqz	v0,0x50e2d4
  50e2cc:	afbf0034 	sw	ra,52(sp)
  50e2d0:	ac400000 	sw	zero,0(v0)
  50e2d4:	afa20010 	sw	v0,16(sp)
  50e2d8:	27a30054 	addiu	v1,sp,84
  50e2dc:	8fa2004c 	lw	v0,76(sp)
  50e2e0:	afa30028 	sw	v1,40(sp)
  50e2e4:	afa3001c 	sw	v1,28(sp)
  50e2e8:	afa20014 	sw	v0,20(sp)
  50e2ec:	8fa20050 	lw	v0,80(sp)
  50e2f0:	0c142f13 	jal	0x50bc4c
  50e2f4:	afa20018 	sw	v0,24(sp)
  50e2f8:	8fbf0034 	lw	ra,52(sp)
  50e2fc:	03e00008 	jr	ra
  50e300:	27bd0038 	addiu	sp,sp,56
