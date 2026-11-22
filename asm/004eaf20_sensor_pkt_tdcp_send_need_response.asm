; func sensor_pkt_tdcp_send_need_response @ 0x004eaf20 size=0x30
  4eaf20:	27bdffd8 	addiu	sp,sp,-40
  4eaf24:	00a03821 	move	a3,a1
  4eaf28:	3085ffff 	andi	a1,a0,0xffff
  4eaf2c:	afa60010 	sw	a2,16(sp)
  4eaf30:	24040001 	li	a0,1
  4eaf34:	3c060080 	lui	a2,0x80
  4eaf38:	afbf0024 	sw	ra,36(sp)
  4eaf3c:	0c143b20 	jal	0x50ec80
  4eaf40:	afa00014 	sw	zero,20(sp)
  4eaf44:	8fbf0024 	lw	ra,36(sp)
  4eaf48:	03e00008 	jr	ra
  4eaf4c:	27bd0028 	addiu	sp,sp,40
