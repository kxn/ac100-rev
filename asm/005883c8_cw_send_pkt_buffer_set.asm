; func cw_send_pkt_buffer_set @ 0x005883c8 size=0x34
  5883c8:	1080000a 	beqz	a0,0x5883f4
  5883cc:	30c6ffff 	andi	a2,a2,0xffff
  5883d0:	8c830010 	lw	v1,16(a0)
  5883d4:	10600007 	beqz	v1,0x5883f4
  5883d8:	00000000 	nop
  5883dc:	10a00005 	beqz	a1,0x5883f4
  5883e0:	00000000 	nop
  5883e4:	10c00003 	beqz	a2,0x5883f4
  5883e8:	00000000 	nop
  5883ec:	08161fd1 	j	0x587f44
  5883f0:	24840010 	addiu	a0,a0,16
  5883f4:	03e00008 	jr	ra
  5883f8:	2402ffff 	li	v0,-1
