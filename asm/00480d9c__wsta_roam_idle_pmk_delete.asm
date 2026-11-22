; func _wsta_roam_idle_pmk_delete @ 0x00480d9c size=0x54
  480d9c:	10800010 	beqz	a0,0x480de0
  480da0:	8ca30000 	lw	v1,0(a1)
  480da4:	3c050076 	lui	a1,0x76
  480da8:	8c870004 	lw	a3,4(a0)
  480dac:	8ca67548 	lw	a2,30024(a1)
  480db0:	2405004c 	li	a1,76
  480db4:	70e52802 	mul	a1,a3,a1
  480db8:	00c52821 	addu	a1,a2,a1
  480dbc:	8ca50000 	lw	a1,0(a1)
  480dc0:	10a00007 	beqz	a1,0x480de0
  480dc4:	00000000 	nop
  480dc8:	8c820048 	lw	v0,72(a0)
  480dcc:	10400004 	beqz	v0,0x480de0
  480dd0:	00000000 	nop
  480dd4:	0062102b 	sltu	v0,v1,v0
  480dd8:	10400003 	beqz	v0,0x480de8
  480ddc:	00000000 	nop
  480de0:	03e00008 	jr	ra
  480de4:	00000000 	nop
  480de8:	0812033f 	j	0x480cfc
  480dec:	00000000 	nop
