; func cw_priv_ap_log_report_para_length @ 0x005a6230 size=0x1c
  5a6230:	90820004 	lbu	v0,4(a0)
  5a6234:	2403000d 	li	v1,13
  5a6238:	24040019 	li	a0,25
  5a623c:	38420001 	xori	v0,v0,0x1
  5a6240:	0082180b 	movn	v1,a0,v0
  5a6244:	03e00008 	jr	ra
  5a6248:	00601021 	move	v0,v1
