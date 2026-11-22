; func cw_80211_station_qos_create @ 0x00568bb0 size=0xdc
  568bb0:	27bdffd8 	addiu	sp,sp,-40
  568bb4:	24050008 	li	a1,8
  568bb8:	afb0001c 	sw	s0,28(sp)
  568bbc:	afbf0024 	sw	ra,36(sp)
  568bc0:	0c15c8cc 	jal	0x572330
  568bc4:	afb10020 	sw	s1,32(sp)
  568bc8:	1040000d 	beqz	v0,0x568c00
  568bcc:	00408021 	move	s0,v0
  568bd0:	2404040d 	li	a0,1037
  568bd4:	24050008 	li	a1,8
  568bd8:	0c15c943 	jal	0x57250c
  568bdc:	00403021 	move	a2,v0
  568be0:	10400017 	beqz	v0,0x568c40
  568be4:	00408821 	move	s1,v0
  568be8:	8fbf0024 	lw	ra,36(sp)
  568bec:	02201021 	move	v0,s1
  568bf0:	8fb10020 	lw	s1,32(sp)
  568bf4:	8fb0001c 	lw	s0,28(sp)
  568bf8:	03e00008 	jr	ra
  568bfc:	27bd0028 	addiu	sp,sp,40
  568c00:	3c020075 	lui	v0,0x75
  568c04:	8c42cf58 	lw	v0,-12456(v0)
  568c08:	1040fff7 	beqz	v0,0x568be8
  568c0c:	00008821 	move	s1,zero
  568c10:	0c16276a 	jal	0x589da8
  568c14:	00000000 	nop
  568c18:	5040fff4 	beqzl	v0,0x568bec
  568c1c:	8fbf0024 	lw	ra,36(sp)
  568c20:	3c04006d 	lui	a0,0x6d
  568c24:	3c05006d 	lui	a1,0x6d
  568c28:	248434fc 	addiu	a0,a0,13564
  568c2c:	24a552d0 	addiu	a1,a1,21200
  568c30:	0c101b74 	jal	0x406dd0
  568c34:	2406009d 	li	a2,157
  568c38:	0815a2fb 	j	0x568bec
  568c3c:	8fbf0024 	lw	ra,36(sp)
  568c40:	3c020075 	lui	v0,0x75
  568c44:	8c42cf58 	lw	v0,-12456(v0)
  568c48:	14400005 	bnez	v0,0x568c60
  568c4c:	00000000 	nop
  568c50:	0c101f7c 	jal	0x407df0
  568c54:	02002021 	move	a0,s0
  568c58:	0815a2fb 	j	0x568bec
  568c5c:	8fbf0024 	lw	ra,36(sp)
  568c60:	0c16276a 	jal	0x589da8
  568c64:	00000000 	nop
  568c68:	1040fff9 	beqz	v0,0x568c50
  568c6c:	3c04006d 	lui	a0,0x6d
  568c70:	3c05006d 	lui	a1,0x6d
  568c74:	24845280 	addiu	a0,a0,21120
  568c78:	24a552d0 	addiu	a1,a1,21200
  568c7c:	0c101b74 	jal	0x406dd0
  568c80:	240600a5 	li	a2,165
  568c84:	0815a314 	j	0x568c50
  568c88:	00000000 	nop
