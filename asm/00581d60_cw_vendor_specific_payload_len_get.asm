; func cw_vendor_specific_payload_len_get @ 0x00581d60 size=0x1c
  581d60:	10800004 	beqz	a0,0x581d74
  581d64:	00001021 	move	v0,zero
  581d68:	94820006 	lhu	v0,6(a0)
  581d6c:	24420006 	addiu	v0,v0,6
  581d70:	3042ffff 	andi	v0,v0,0xffff
  581d74:	03e00008 	jr	ra
  581d78:	00000000 	nop
