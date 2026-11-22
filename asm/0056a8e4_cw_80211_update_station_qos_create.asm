; func cw_80211_update_station_qos_create @ 0x0056a8e4 size=0xdc
  56a8e4:	27bdffd8 	addiu	sp,sp,-40
  56a8e8:	2405000f 	li	a1,15
  56a8ec:	afb0001c 	sw	s0,28(sp)
  56a8f0:	afbf0024 	sw	ra,36(sp)
  56a8f4:	0c15c8cc 	jal	0x572330
  56a8f8:	afb10020 	sw	s1,32(sp)
  56a8fc:	1040000d 	beqz	v0,0x56a934
  56a900:	00408021 	move	s0,v0
  56a904:	24040413 	li	a0,1043
  56a908:	2405000f 	li	a1,15
  56a90c:	0c15c943 	jal	0x57250c
  56a910:	00403021 	move	a2,v0
  56a914:	10400017 	beqz	v0,0x56a974
  56a918:	00408821 	move	s1,v0
  56a91c:	8fbf0024 	lw	ra,36(sp)
  56a920:	02201021 	move	v0,s1
  56a924:	8fb10020 	lw	s1,32(sp)
  56a928:	8fb0001c 	lw	s0,28(sp)
  56a92c:	03e00008 	jr	ra
  56a930:	27bd0028 	addiu	sp,sp,40
  56a934:	3c020075 	lui	v0,0x75
  56a938:	8c42cf58 	lw	v0,-12456(v0)
  56a93c:	1040fff7 	beqz	v0,0x56a91c
  56a940:	00008821 	move	s1,zero
  56a944:	0c16276a 	jal	0x589da8
  56a948:	00000000 	nop
  56a94c:	5040fff4 	beqzl	v0,0x56a920
  56a950:	8fbf0024 	lw	ra,36(sp)
  56a954:	3c04006d 	lui	a0,0x6d
  56a958:	3c05006d 	lui	a1,0x6d
  56a95c:	248434fc 	addiu	a0,a0,13564
  56a960:	24a559f0 	addiu	a1,a1,23024
  56a964:	0c101b74 	jal	0x406dd0
  56a968:	240600de 	li	a2,222
  56a96c:	0815aa48 	j	0x56a920
  56a970:	8fbf0024 	lw	ra,36(sp)
  56a974:	3c020075 	lui	v0,0x75
  56a978:	8c42cf58 	lw	v0,-12456(v0)
  56a97c:	14400005 	bnez	v0,0x56a994
  56a980:	00000000 	nop
  56a984:	0c101f7c 	jal	0x407df0
  56a988:	02002021 	move	a0,s0
  56a98c:	0815aa48 	j	0x56a920
  56a990:	8fbf0024 	lw	ra,36(sp)
  56a994:	0c16276a 	jal	0x589da8
  56a998:	00000000 	nop
  56a99c:	1040fff9 	beqz	v0,0x56a984
  56a9a0:	3c04006d 	lui	a0,0x6d
  56a9a4:	3c05006d 	lui	a1,0x6d
  56a9a8:	248447f0 	addiu	a0,a0,18416
  56a9ac:	24a559f0 	addiu	a1,a1,23024
  56a9b0:	0c101b74 	jal	0x406dd0
  56a9b4:	240600e6 	li	a2,230
  56a9b8:	0815aa61 	j	0x56a984
  56a9bc:	00000000 	nop
