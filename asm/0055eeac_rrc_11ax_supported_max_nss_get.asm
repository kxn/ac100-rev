; func rrc_11ax_supported_max_nss_get @ 0x0055eeac size=0x24
  55eeac:	10800006 	beqz	a0,0x55eec8
  55eeb0:	2402ffff 	li	v0,-1
  55eeb4:	10a00004 	beqz	a1,0x55eec8
  55eeb8:	00000000 	nop
  55eebc:	8c8201ac 	lw	v0,428(a0)
  55eec0:	aca20000 	sw	v0,0(a1)
  55eec4:	00001021 	move	v0,zero
  55eec8:	03e00008 	jr	ra
  55eecc:	00000000 	nop
