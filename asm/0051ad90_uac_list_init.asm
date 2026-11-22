; func uac_list_init @ 0x0051ad90 size=0x50
  51ad90:	3c1c0024 	lui	gp,0x24
  51ad94:	279c6370 	addiu	gp,gp,25456
  51ad98:	0399e021 	addu	gp,gp,t9
  51ad9c:	50800006 	beqzl	a0,0x51adb8
  51ada0:	8f828320 	lw	v0,-31968(gp)
  51ada4:	ac840000 	sw	a0,0(a0)
  51ada8:	ac840004 	sw	a0,4(a0)
  51adac:	ac800008 	sw	zero,8(a0)
  51adb0:	03e00008 	jr	ra
  51adb4:	00000000 	nop
  51adb8:	8c420000 	lw	v0,0(v0)
  51adbc:	1040fffc 	beqz	v0,0x51adb0
  51adc0:	00000000 	nop
  51adc4:	8f848028 	lw	a0,-32728(gp)
  51adc8:	2406004f 	li	a2,79
  51adcc:	8f858028 	lw	a1,-32728(gp)
  51add0:	8f9987d0 	lw	t9,-30768(gp)
  51add4:	248424a0 	addiu	a0,a0,9376
  51add8:	03200008 	jr	t9
  51addc:	24a525d0 	addiu	a1,a1,9680
