; func register_notify_ap_begin_report_flag_mask @ 0x0049dc80 size=0x30
  49dc80:	2c830002 	sltiu	v1,a0,2
  49dc84:	10600008 	beqz	v1,0x49dca8
  49dc88:	2402ffff 	li	v0,-1
  49dc8c:	3c020076 	lui	v0,0x76
  49dc90:	24030001 	li	v1,1
  49dc94:	00832004 	sllv	a0,v1,a0
  49dc98:	8c4378f0 	lw	v1,30960(v0)
  49dc9c:	00832025 	or	a0,a0,v1
  49dca0:	ac4478f0 	sw	a0,30960(v0)
  49dca4:	00001021 	move	v0,zero
  49dca8:	03e00008 	jr	ra
  49dcac:	00000000 	nop
