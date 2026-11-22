; func cw_80211_mic_countermeasures_create @ 0x00566aa8 size=0xdc
  566aa8:	27bdffd8 	addiu	sp,sp,-40
  566aac:	24050008 	li	a1,8
  566ab0:	afb0001c 	sw	s0,28(sp)
  566ab4:	afbf0024 	sw	ra,36(sp)
  566ab8:	0c15c8cc 	jal	0x572330
  566abc:	afb10020 	sw	s1,32(sp)
  566ac0:	1040000d 	beqz	v0,0x566af8
  566ac4:	00408021 	move	s0,v0
  566ac8:	24040407 	li	a0,1031
  566acc:	24050008 	li	a1,8
  566ad0:	0c15c943 	jal	0x57250c
  566ad4:	00403021 	move	a2,v0
  566ad8:	10400017 	beqz	v0,0x566b38
  566adc:	00408821 	move	s1,v0
  566ae0:	8fbf0024 	lw	ra,36(sp)
  566ae4:	02201021 	move	v0,s1
  566ae8:	8fb10020 	lw	s1,32(sp)
  566aec:	8fb0001c 	lw	s0,28(sp)
  566af0:	03e00008 	jr	ra
  566af4:	27bd0028 	addiu	sp,sp,40
  566af8:	3c020075 	lui	v0,0x75
  566afc:	8c42cf58 	lw	v0,-12456(v0)
  566b00:	1040fff7 	beqz	v0,0x566ae0
  566b04:	00008821 	move	s1,zero
  566b08:	0c16276a 	jal	0x589da8
  566b0c:	00000000 	nop
  566b10:	5040fff4 	beqzl	v0,0x566ae4
  566b14:	8fbf0024 	lw	ra,36(sp)
  566b18:	3c04006d 	lui	a0,0x6d
  566b1c:	3c05006d 	lui	a1,0x6d
  566b20:	248434fc 	addiu	a0,a0,13564
  566b24:	24a54950 	addiu	a1,a1,18768
  566b28:	0c101b74 	jal	0x406dd0
  566b2c:	240600bd 	li	a2,189
  566b30:	08159ab9 	j	0x566ae4
  566b34:	8fbf0024 	lw	ra,36(sp)
  566b38:	3c020075 	lui	v0,0x75
  566b3c:	8c42cf58 	lw	v0,-12456(v0)
  566b40:	14400005 	bnez	v0,0x566b58
  566b44:	00000000 	nop
  566b48:	0c101f7c 	jal	0x407df0
  566b4c:	02002021 	move	a0,s0
  566b50:	08159ab9 	j	0x566ae4
  566b54:	8fbf0024 	lw	ra,36(sp)
  566b58:	0c16276a 	jal	0x589da8
  566b5c:	00000000 	nop
  566b60:	1040fff9 	beqz	v0,0x566b48
  566b64:	3c04006d 	lui	a0,0x6d
  566b68:	3c05006d 	lui	a1,0x6d
  566b6c:	24843580 	addiu	a0,a0,13696
  566b70:	24a54950 	addiu	a1,a1,18768
  566b74:	0c101b74 	jal	0x406dd0
  566b78:	240600c5 	li	a2,197
  566b7c:	08159ad2 	j	0x566b48
  566b80:	00000000 	nop
	...
