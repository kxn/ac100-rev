; func cw_add_station_create @ 0x0056ff1c size=0x1e4
  56ff1c:	27bdffd8 	addiu	sp,sp,-40
  56ff20:	24050010 	li	a1,16
  56ff24:	afb10020 	sw	s1,32(sp)
  56ff28:	afb0001c 	sw	s0,28(sp)
  56ff2c:	afbf0024 	sw	ra,36(sp)
  56ff30:	0c15c8cc 	jal	0x572330
  56ff34:	00808821 	move	s1,a0
  56ff38:	1040004a 	beqz	v0,0x570064
  56ff3c:	00408021 	move	s0,v0
  56ff40:	ac400004 	sw	zero,4(v0)
  56ff44:	ac40000c 	sw	zero,12(v0)
  56ff48:	8e240004 	lw	a0,4(s1)
  56ff4c:	10800006 	beqz	a0,0x56ff68
  56ff50:	24020006 	li	v0,6
  56ff54:	92250001 	lbu	a1,1(s1)
  56ff58:	10a20019 	beq	a1,v0,0x56ffc0
  56ff5c:	24020008 	li	v0,8
  56ff60:	10a20017 	beq	a1,v0,0x56ffc0
  56ff64:	00000000 	nop
  56ff68:	8e24000c 	lw	a0,12(s1)
  56ff6c:	50800005 	beqzl	a0,0x56ff84
  56ff70:	96050008 	lhu	a1,8(s0)
  56ff74:	96250008 	lhu	a1,8(s1)
  56ff78:	14a0001d 	bnez	a1,0x56fff0
  56ff7c:	00000000 	nop
  56ff80:	96050008 	lhu	a1,8(s0)
  56ff84:	24040008 	li	a0,8
  56ff88:	92020001 	lbu	v0,1(s0)
  56ff8c:	02003021 	move	a2,s0
  56ff90:	24a50002 	addiu	a1,a1,2
  56ff94:	00a22821 	addu	a1,a1,v0
  56ff98:	0c15c943 	jal	0x57250c
  56ff9c:	30a5ffff 	andi	a1,a1,0xffff
  56ffa0:	1040001e 	beqz	v0,0x57001c
  56ffa4:	00408821 	move	s1,v0
  56ffa8:	8fbf0024 	lw	ra,36(sp)
  56ffac:	02201021 	move	v0,s1
  56ffb0:	8fb10020 	lw	s1,32(sp)
  56ffb4:	8fb0001c 	lw	s0,28(sp)
  56ffb8:	03e00008 	jr	ra
  56ffbc:	27bd0028 	addiu	sp,sp,40
  56ffc0:	0c15c8cc 	jal	0x572330
  56ffc4:	00000000 	nop
  56ffc8:	1440ffe7 	bnez	v0,0x56ff68
  56ffcc:	ae020004 	sw	v0,4(s0)
  56ffd0:	3c020075 	lui	v0,0x75
  56ffd4:	8c42cf58 	lw	v0,-12456(v0)
  56ffd8:	1440003e 	bnez	v0,0x5700d4
  56ffdc:	00000000 	nop
  56ffe0:	0c101f7c 	jal	0x407df0
  56ffe4:	02002021 	move	a0,s0
  56ffe8:	0815bfea 	j	0x56ffa8
  56ffec:	00008821 	move	s1,zero
  56fff0:	0c15c909 	jal	0x572424
  56fff4:	00000000 	nop
  56fff8:	1440ffe1 	bnez	v0,0x56ff80
  56fffc:	ae02000c 	sw	v0,12(s0)
  570000:	8e040004 	lw	a0,4(s0)
  570004:	1080fff6 	beqz	a0,0x56ffe0
  570008:	00000000 	nop
  57000c:	0c101f7c 	jal	0x407df0
  570010:	00000000 	nop
  570014:	0815bff8 	j	0x56ffe0
  570018:	00000000 	nop
  57001c:	3c020075 	lui	v0,0x75
  570020:	8c42cf58 	lw	v0,-12456(v0)
  570024:	1440001f 	bnez	v0,0x5700a4
  570028:	00000000 	nop
  57002c:	8e040004 	lw	a0,4(s0)
  570030:	50800004 	beqzl	a0,0x570044
  570034:	8e04000c 	lw	a0,12(s0)
  570038:	0c101f7c 	jal	0x407df0
  57003c:	00000000 	nop
  570040:	8e04000c 	lw	a0,12(s0)
  570044:	10800003 	beqz	a0,0x570054
  570048:	00000000 	nop
  57004c:	0c101f7c 	jal	0x407df0
  570050:	00000000 	nop
  570054:	0c101f7c 	jal	0x407df0
  570058:	02002021 	move	a0,s0
  57005c:	0815bfeb 	j	0x56ffac
  570060:	8fbf0024 	lw	ra,36(sp)
  570064:	3c020075 	lui	v0,0x75
  570068:	8c42cf58 	lw	v0,-12456(v0)
  57006c:	1040ffce 	beqz	v0,0x56ffa8
  570070:	00008821 	move	s1,zero
  570074:	0c16276a 	jal	0x589da8
  570078:	00000000 	nop
  57007c:	5040ffcb 	beqzl	v0,0x56ffac
  570080:	8fbf0024 	lw	ra,36(sp)
  570084:	3c04006d 	lui	a0,0x6d
  570088:	3c05006d 	lui	a1,0x6d
  57008c:	248434fc 	addiu	a0,a0,13564
  570090:	24a57740 	addiu	a1,a1,30528
  570094:	0c101b74 	jal	0x406dd0
  570098:	24060102 	li	a2,258
  57009c:	0815bfeb 	j	0x56ffac
  5700a0:	8fbf0024 	lw	ra,36(sp)
  5700a4:	0c16276a 	jal	0x589da8
  5700a8:	00000000 	nop
  5700ac:	5040ffe0 	beqzl	v0,0x570030
  5700b0:	8e040004 	lw	a0,4(s0)
  5700b4:	3c04006d 	lui	a0,0x6d
  5700b8:	3c05006d 	lui	a1,0x6d
  5700bc:	24843580 	addiu	a0,a0,13696
  5700c0:	24a57740 	addiu	a1,a1,30528
  5700c4:	0c101b74 	jal	0x406dd0
  5700c8:	24060127 	li	a2,295
  5700cc:	0815c00c 	j	0x570030
  5700d0:	8e040004 	lw	a0,4(s0)
  5700d4:	0c16276a 	jal	0x589da8
  5700d8:	00000000 	nop
  5700dc:	1040ffc0 	beqz	v0,0x56ffe0
  5700e0:	3c04006d 	lui	a0,0x6d
  5700e4:	3c05006d 	lui	a1,0x6d
  5700e8:	24847698 	addiu	a0,a0,30360
  5700ec:	24a57740 	addiu	a1,a1,30528
  5700f0:	0c101b74 	jal	0x406dd0
  5700f4:	2406010e 	li	a2,270
  5700f8:	0815bff8 	j	0x56ffe0
  5700fc:	00000000 	nop
