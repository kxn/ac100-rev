; func unregister_notify_ap_begin_report_flag_mask @ 0x0049dcb0 size=0x34
  49dcb0:	2c830002 	sltiu	v1,a0,2
  49dcb4:	10600009 	beqz	v1,0x49dcdc
  49dcb8:	2402ffff 	li	v0,-1
  49dcbc:	3c020076 	lui	v0,0x76
  49dcc0:	24030001 	li	v1,1
  49dcc4:	00832004 	sllv	a0,v1,a0
  49dcc8:	8c4378f0 	lw	v1,30960(v0)
  49dccc:	00042027 	nor	a0,zero,a0
  49dcd0:	00832024 	and	a0,a0,v1
  49dcd4:	ac4478f0 	sw	a0,30960(v0)
  49dcd8:	00001021 	move	v0,zero
  49dcdc:	03e00008 	jr	ra
  49dce0:	00000000 	nop
