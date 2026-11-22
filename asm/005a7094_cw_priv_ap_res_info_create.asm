; func cw_priv_ap_res_info_create @ 0x005a7094 size=0xdc
  5a7094:	27bdffd8 	addiu	sp,sp,-40
  5a7098:	24050006 	li	a1,6
  5a709c:	afb0001c 	sw	s0,28(sp)
  5a70a0:	afbf0024 	sw	ra,36(sp)
  5a70a4:	0c15c8cc 	jal	0x572330
  5a70a8:	afb10020 	sw	s1,32(sp)
  5a70ac:	1040000d 	beqz	v0,0x5a70e4
  5a70b0:	00408021 	move	s0,v0
  5a70b4:	24040025 	li	a0,37
  5a70b8:	24050005 	li	a1,5
  5a70bc:	0c15c943 	jal	0x57250c
  5a70c0:	00403021 	move	a2,v0
  5a70c4:	10400017 	beqz	v0,0x5a7124
  5a70c8:	00408821 	move	s1,v0
  5a70cc:	8fbf0024 	lw	ra,36(sp)
  5a70d0:	02201021 	move	v0,s1
  5a70d4:	8fb10020 	lw	s1,32(sp)
  5a70d8:	8fb0001c 	lw	s0,28(sp)
  5a70dc:	03e00008 	jr	ra
  5a70e0:	27bd0028 	addiu	sp,sp,40
  5a70e4:	3c020075 	lui	v0,0x75
  5a70e8:	8c42cf58 	lw	v0,-12456(v0)
  5a70ec:	1040fff7 	beqz	v0,0x5a70cc
  5a70f0:	00008821 	move	s1,zero
  5a70f4:	0c16276a 	jal	0x589da8
  5a70f8:	00000000 	nop
  5a70fc:	5040fff4 	beqzl	v0,0x5a70d0
  5a7100:	8fbf0024 	lw	ra,36(sp)
  5a7104:	3c04006d 	lui	a0,0x6d
  5a7108:	3c05006f 	lui	a1,0x6f
  5a710c:	248434fc 	addiu	a0,a0,13564
  5a7110:	24a58200 	addiu	a1,a1,-32256
  5a7114:	0c101b74 	jal	0x406dd0
  5a7118:	240600b5 	li	a2,181
  5a711c:	08169c34 	j	0x5a70d0
  5a7120:	8fbf0024 	lw	ra,36(sp)
  5a7124:	3c020075 	lui	v0,0x75
  5a7128:	8c42cf58 	lw	v0,-12456(v0)
  5a712c:	14400005 	bnez	v0,0x5a7144
  5a7130:	00000000 	nop
  5a7134:	0c101f7c 	jal	0x407df0
  5a7138:	02002021 	move	a0,s0
  5a713c:	08169c34 	j	0x5a70d0
  5a7140:	8fbf0024 	lw	ra,36(sp)
  5a7144:	0c16276a 	jal	0x589da8
  5a7148:	00000000 	nop
  5a714c:	1040fff9 	beqz	v0,0x5a7134
  5a7150:	3c04006d 	lui	a0,0x6d
  5a7154:	3c05006f 	lui	a1,0x6f
  5a7158:	248447f0 	addiu	a0,a0,18416
  5a715c:	24a58200 	addiu	a1,a1,-32256
  5a7160:	0c101b74 	jal	0x406dd0
  5a7164:	240600bd 	li	a2,189
  5a7168:	08169c4d 	j	0x5a7134
  5a716c:	00000000 	nop
