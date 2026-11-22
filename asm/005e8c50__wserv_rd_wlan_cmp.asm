; func _wserv_rd_wlan_cmp @ 0x005e8c50 size=0x38
  5e8c50:	10800007 	beqz	a0,0x5e8c70
  5e8c54:	00001021 	move	v0,zero
  5e8c58:	10a00005 	beqz	a1,0x5e8c70
  5e8c5c:	00000000 	nop
  5e8c60:	8c860000 	lw	a2,0(a0)
  5e8c64:	8ca30000 	lw	v1,0(a1)
  5e8c68:	50c30003 	beql	a2,v1,0x5e8c78
  5e8c6c:	90830004 	lbu	v1,4(a0)
  5e8c70:	03e00008 	jr	ra
  5e8c74:	00000000 	nop
  5e8c78:	90a20004 	lbu	v0,4(a1)
  5e8c7c:	00621026 	xor	v0,v1,v0
  5e8c80:	03e00008 	jr	ra
  5e8c84:	2c420001 	sltiu	v0,v0,1
