; func estimate_snr_from_rcpi @ 0x0048adcc size=0x20
  48adcc:	7c042420 	seb	a0,a0
  48add0:	2883ffa2 	slti	v1,a0,-94
  48add4:	14600003 	bnez	v1,0x48ade4
  48add8:	00001021 	move	v0,zero
  48addc:	2482005f 	addiu	v0,a0,95
  48ade0:	304200ff 	andi	v0,v0,0xff
  48ade4:	03e00008 	jr	ra
  48ade8:	00000000 	nop
