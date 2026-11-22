; func serv_retransmit_packet_send @ 0x0059af98 size=0x38
  59af98:	00e64025 	or	t0,a3,a2
  59af9c:	8fa20010 	lw	v0,16(sp)
  59afa0:	11000005 	beqz	t0,0x59afb8
  59afa4:	24030001 	li	v1,1
  59afa8:	14c00006 	bnez	a2,0x59afc4
  59afac:	24030004 	li	v1,4
  59afb0:	24060003 	li	a2,3
  59afb4:	00c7180b 	movn	v1,a2,a3
  59afb8:	00603021 	move	a2,v1
  59afbc:	0816691d 	j	0x59a474
  59afc0:	00403821 	move	a3,v0
  59afc4:	24060002 	li	a2,2
  59afc8:	08166bee 	j	0x59afb8
  59afcc:	00c7180a 	movz	v1,a2,a3
