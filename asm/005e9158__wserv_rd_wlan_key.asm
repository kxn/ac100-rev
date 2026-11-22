; func _wserv_rd_wlan_key @ 0x005e9158 size=0x38
  5e9158:	27bdffe0 	addiu	sp,sp,-32
  5e915c:	24050004 	li	a1,4
  5e9160:	00003021 	move	a2,zero
  5e9164:	afb00018 	sw	s0,24(sp)
  5e9168:	afbf001c 	sw	ra,28(sp)
  5e916c:	0c1020f4 	jal	0x4083d0
  5e9170:	00808021 	move	s0,a0
  5e9174:	26040004 	addiu	a0,s0,4
  5e9178:	8fbf001c 	lw	ra,28(sp)
  5e917c:	24050001 	li	a1,1
  5e9180:	8fb00018 	lw	s0,24(sp)
  5e9184:	27bd0020 	addiu	sp,sp,32
  5e9188:	081020f4 	j	0x4083d0
  5e918c:	00403021 	move	a2,v0
