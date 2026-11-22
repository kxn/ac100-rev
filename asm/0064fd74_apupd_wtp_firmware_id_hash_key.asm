; func apupd_wtp_firmware_id_hash_key @ 0x0064fd74 size=0x6c
  64fd74:	27bdffe0 	addiu	sp,sp,-32
  64fd78:	10800006 	beqz	a0,0x64fd94
  64fd7c:	afbf001c 	sw	ra,28(sp)
  64fd80:	8fbf001c 	lw	ra,28(sp)
  64fd84:	24050010 	li	a1,16
  64fd88:	00003021 	move	a2,zero
  64fd8c:	081020f4 	j	0x4083d0
  64fd90:	27bd0020 	addiu	sp,sp,32
  64fd94:	3c020076 	lui	v0,0x76
  64fd98:	8c428c08 	lw	v0,-29688(v0)
  64fd9c:	14400004 	bnez	v0,0x64fdb0
  64fda0:	8fbf001c 	lw	ra,28(sp)
  64fda4:	00001021 	move	v0,zero
  64fda8:	03e00008 	jr	ra
  64fdac:	27bd0020 	addiu	sp,sp,32
  64fdb0:	0c16276a 	jal	0x589da8
  64fdb4:	00000000 	nop
  64fdb8:	5040fffa 	beqzl	v0,0x64fda4
  64fdbc:	8fbf001c 	lw	ra,28(sp)
  64fdc0:	3c040071 	lui	a0,0x71
  64fdc4:	3c050072 	lui	a1,0x72
  64fdc8:	24840720 	addiu	a0,a0,1824
  64fdcc:	24a59f9c 	addiu	a1,a1,-24676
  64fdd0:	0c101b74 	jal	0x406dd0
  64fdd4:	2406032f 	li	a2,815
  64fdd8:	08193f69 	j	0x64fda4
  64fddc:	8fbf001c 	lw	ra,28(sp)
