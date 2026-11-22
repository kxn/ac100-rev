; func sensor_pkt_tdcp_send @ 0x004eaef0 size=0x30
  4eaef0:	27bdffd8 	addiu	sp,sp,-40
  4eaef4:	00a03821 	move	a3,a1
  4eaef8:	3c060080 	lui	a2,0x80
  4eaefc:	3085ffff 	andi	a1,a0,0xffff
  4eaf00:	afbf0024 	sw	ra,36(sp)
  4eaf04:	00002021 	move	a0,zero
  4eaf08:	afa00010 	sw	zero,16(sp)
  4eaf0c:	0c143b20 	jal	0x50ec80
  4eaf10:	afa00014 	sw	zero,20(sp)
  4eaf14:	8fbf0024 	lw	ra,36(sp)
  4eaf18:	03e00008 	jr	ra
  4eaf1c:	27bd0028 	addiu	sp,sp,40
