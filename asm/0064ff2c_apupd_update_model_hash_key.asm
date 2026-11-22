; func apupd_update_model_hash_key @ 0x0064ff2c size=0x6c
  64ff2c:	27bdffe0 	addiu	sp,sp,-32
  64ff30:	10800006 	beqz	a0,0x64ff4c
  64ff34:	afbf001c 	sw	ra,28(sp)
  64ff38:	8fbf001c 	lw	ra,28(sp)
  64ff3c:	24050004 	li	a1,4
  64ff40:	00003021 	move	a2,zero
  64ff44:	081020f4 	j	0x4083d0
  64ff48:	27bd0020 	addiu	sp,sp,32
  64ff4c:	3c020076 	lui	v0,0x76
  64ff50:	8c428c08 	lw	v0,-29688(v0)
  64ff54:	14400004 	bnez	v0,0x64ff68
  64ff58:	8fbf001c 	lw	ra,28(sp)
  64ff5c:	00001021 	move	v0,zero
  64ff60:	03e00008 	jr	ra
  64ff64:	27bd0020 	addiu	sp,sp,32
  64ff68:	0c16276a 	jal	0x589da8
  64ff6c:	00000000 	nop
  64ff70:	5040fffa 	beqzl	v0,0x64ff5c
  64ff74:	8fbf001c 	lw	ra,28(sp)
  64ff78:	3c040071 	lui	a0,0x71
  64ff7c:	3c050072 	lui	a1,0x72
  64ff80:	24840720 	addiu	a0,a0,1824
  64ff84:	24a5a15c 	addiu	a1,a1,-24228
  64ff88:	0c101b74 	jal	0x406dd0
  64ff8c:	24060297 	li	a2,663
  64ff90:	08193fd7 	j	0x64ff5c
  64ff94:	8fbf001c 	lw	ra,28(sp)
