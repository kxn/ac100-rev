; func apupd_update_wtp_hash_key @ 0x0064fe50 size=0x6c
  64fe50:	27bdffe0 	addiu	sp,sp,-32
  64fe54:	10800006 	beqz	a0,0x64fe70
  64fe58:	afbf001c 	sw	ra,28(sp)
  64fe5c:	8fbf001c 	lw	ra,28(sp)
  64fe60:	24050006 	li	a1,6
  64fe64:	00003021 	move	a2,zero
  64fe68:	081020f4 	j	0x4083d0
  64fe6c:	27bd0020 	addiu	sp,sp,32
  64fe70:	3c020076 	lui	v0,0x76
  64fe74:	8c428c08 	lw	v0,-29688(v0)
  64fe78:	14400004 	bnez	v0,0x64fe8c
  64fe7c:	8fbf001c 	lw	ra,28(sp)
  64fe80:	00001021 	move	v0,zero
  64fe84:	03e00008 	jr	ra
  64fe88:	27bd0020 	addiu	sp,sp,32
  64fe8c:	0c16276a 	jal	0x589da8
  64fe90:	00000000 	nop
  64fe94:	5040fffa 	beqzl	v0,0x64fe80
  64fe98:	8fbf001c 	lw	ra,28(sp)
  64fe9c:	3c040071 	lui	a0,0x71
  64fea0:	3c050072 	lui	a1,0x72
  64fea4:	24840720 	addiu	a0,a0,1824
  64fea8:	24a5a108 	addiu	a1,a1,-24312
  64feac:	0c101b74 	jal	0x406dd0
  64feb0:	240602e3 	li	a2,739
  64feb4:	08193fa0 	j	0x64fe80
  64feb8:	8fbf001c 	lw	ra,28(sp)
