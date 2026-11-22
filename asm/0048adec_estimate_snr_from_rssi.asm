; func estimate_snr_from_rssi @ 0x0048adec size=0x24
  48adec:	7c052c20 	seb	a1,a1
  48adf0:	14a00004 	bnez	a1,0x48ae04
  48adf4:	7c042420 	seb	a0,a0
  48adf8:	2484005f 	addiu	a0,a0,95
  48adfc:	03e00008 	jr	ra
  48ae00:	308200ff 	andi	v0,a0,0xff
  48ae04:	00852023 	subu	a0,a0,a1
  48ae08:	03e00008 	jr	ra
  48ae0c:	308200ff 	andi	v0,a0,0xff
