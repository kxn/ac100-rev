; func cw_priv_chnl_scan_report_length @ 0x005add30 size=0x1c
  5add30:	10800004 	beqz	a0,0x5add44
  5add34:	00001021 	move	v0,zero
  5add38:	90830000 	lbu	v1,0(a0)
  5add3c:	24020009 	li	v0,9
  5add40:	70621002 	mul	v0,v1,v0
  5add44:	03e00008 	jr	ra
  5add48:	00000000 	nop
