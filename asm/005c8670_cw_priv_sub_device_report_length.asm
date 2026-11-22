; func cw_priv_sub_device_report_length @ 0x005c8670 size=0x1c
  5c8670:	10800004 	beqz	a0,0x5c8684
  5c8674:	00001021 	move	v0,zero
  5c8678:	8c820004 	lw	v0,4(a0)
  5c867c:	24420008 	addiu	v0,v0,8
  5c8680:	3042ffff 	andi	v0,v0,0xffff
  5c8684:	03e00008 	jr	ra
  5c8688:	00000000 	nop
