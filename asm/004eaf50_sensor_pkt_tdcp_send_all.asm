; func sensor_pkt_tdcp_send_all @ 0x004eaf50 size=0x2c
  4eaf50:	27bdffd8 	addiu	sp,sp,-40
  4eaf54:	00803021 	move	a2,a0
  4eaf58:	3c050080 	lui	a1,0x80
  4eaf5c:	00002021 	move	a0,zero
  4eaf60:	afbf0024 	sw	ra,36(sp)
  4eaf64:	00003821 	move	a3,zero
  4eaf68:	0c143bd6 	jal	0x50ef58
  4eaf6c:	afa00010 	sw	zero,16(sp)
  4eaf70:	8fbf0024 	lw	ra,36(sp)
  4eaf74:	03e00008 	jr	ra
  4eaf78:	27bd0028 	addiu	sp,sp,40
