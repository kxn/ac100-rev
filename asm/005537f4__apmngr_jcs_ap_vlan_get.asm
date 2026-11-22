; func _apmngr_jcs_ap_vlan_get @ 0x005537f4 size=0x5c
  5537f4:	27bdffd8 	addiu	sp,sp,-40
  5537f8:	00801021 	move	v0,a0
  5537fc:	afb00020 	sw	s0,32(sp)
  553800:	00c08021 	move	s0,a2
  553804:	afbf0024 	sw	ra,36(sp)
  553808:	27a60018 	addiu	a2,sp,24
  55380c:	a7a00018 	sh	zero,24(sp)
  553810:	8c840000 	lw	a0,0(a0)
  553814:	0c17c861 	jal	0x5f2184
  553818:	90450004 	lbu	a1,4(v0)
  55381c:	97a40018 	lhu	a0,24(sp)
  553820:	10800007 	beqz	a0,0x553840
  553824:	8fbf0024 	lw	ra,36(sp)
  553828:	0c101d34 	jal	0x4074d0
  55382c:	00000000 	nop
  553830:	02002021 	move	a0,s0
  553834:	0c101c74 	jal	0x4071d0
  553838:	00402821 	move	a1,v0
  55383c:	8fbf0024 	lw	ra,36(sp)
  553840:	00001021 	move	v0,zero
  553844:	8fb00020 	lw	s0,32(sp)
  553848:	03e00008 	jr	ra
  55384c:	27bd0028 	addiu	sp,sp,40
