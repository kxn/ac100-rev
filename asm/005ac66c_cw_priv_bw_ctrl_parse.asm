; func cw_priv_bw_ctrl_parse @ 0x005ac66c size=0x350
  5ac66c:	27bdffc0 	addiu	sp,sp,-64
  5ac670:	afb50034 	sw	s5,52(sp)
  5ac674:	00a0a821 	move	s5,a1
  5ac678:	afb3002c 	sw	s3,44(sp)
  5ac67c:	2405007a 	li	a1,122
  5ac680:	afb20028 	sw	s2,40(sp)
  5ac684:	00809821 	move	s3,a0
  5ac688:	afbf003c 	sw	ra,60(sp)
  5ac68c:	afb60038 	sw	s6,56(sp)
  5ac690:	afb40030 	sw	s4,48(sp)
  5ac694:	afb10024 	sw	s1,36(sp)
  5ac698:	afb00020 	sw	s0,32(sp)
  5ac69c:	94960006 	lhu	s6,6(a0)
  5ac6a0:	0c102114 	jal	0x408450
  5ac6a4:	24040010 	li	a0,16
  5ac6a8:	1040003a 	beqz	v0,0x5ac794
  5ac6ac:	00409021 	move	s2,v0
  5ac6b0:	00002821 	move	a1,zero
  5ac6b4:	24060010 	li	a2,16
  5ac6b8:	0c101cf0 	jal	0x4073c0
  5ac6bc:	00402021 	move	a0,v0
  5ac6c0:	0c15c5b0 	jal	0x5716c0
  5ac6c4:	02602021 	move	a0,s3
  5ac6c8:	a2420000 	sb	v0,0(s2)
  5ac6cc:	2c420005 	sltiu	v0,v0,5
  5ac6d0:	14400013 	bnez	v0,0x5ac720
  5ac6d4:	3c020075 	lui	v0,0x75
  5ac6d8:	8c42cf58 	lw	v0,-12456(v0)
  5ac6dc:	1440003d 	bnez	v0,0x5ac7d4
  5ac6e0:	00000000 	nop
  5ac6e4:	12400004 	beqz	s2,0x5ac6f8
  5ac6e8:	2402ffff 	li	v0,-1
  5ac6ec:	0c101f7c 	jal	0x407df0
  5ac6f0:	02402021 	move	a0,s2
  5ac6f4:	2402ffff 	li	v0,-1
  5ac6f8:	8fbf003c 	lw	ra,60(sp)
  5ac6fc:	8fb60038 	lw	s6,56(sp)
  5ac700:	8fb50034 	lw	s5,52(sp)
  5ac704:	8fb40030 	lw	s4,48(sp)
  5ac708:	8fb3002c 	lw	s3,44(sp)
  5ac70c:	8fb20028 	lw	s2,40(sp)
  5ac710:	8fb10024 	lw	s1,36(sp)
  5ac714:	8fb00020 	lw	s0,32(sp)
  5ac718:	03e00008 	jr	ra
  5ac71c:	27bd0040 	addiu	sp,sp,64
  5ac720:	0c15c5ff 	jal	0x5717fc
  5ac724:	02602021 	move	a0,s3
  5ac728:	02602021 	move	a0,s3
  5ac72c:	0c15c5ff 	jal	0x5717fc
  5ac730:	ae420004 	sw	v0,4(s2)
  5ac734:	ae420008 	sw	v0,8(s2)
  5ac738:	92420000 	lbu	v0,0(s2)
  5ac73c:	10400033 	beqz	v0,0x5ac80c
  5ac740:	24030004 	li	v1,4
  5ac744:	10430031 	beq	v0,v1,0x5ac80c
  5ac748:	00000000 	nop
  5ac74c:	24040002 	li	a0,2
  5ac750:	0c102114 	jal	0x408450
  5ac754:	240500a5 	li	a1,165
  5ac758:	10400071 	beqz	v0,0x5ac920
  5ac75c:	00408021 	move	s0,v0
  5ac760:	0c15c5b0 	jal	0x5716c0
  5ac764:	02602021 	move	a0,s3
  5ac768:	a2020000 	sb	v0,0(s0)
  5ac76c:	2c420020 	sltiu	v0,v0,32
  5ac770:	1440003d 	bnez	v0,0x5ac868
  5ac774:	3c020075 	lui	v0,0x75
  5ac778:	8c42cf58 	lw	v0,-12456(v0)
  5ac77c:	14400078 	bnez	v0,0x5ac960
  5ac780:	00000000 	nop
  5ac784:	0c101f7c 	jal	0x407df0
  5ac788:	02002021 	move	a0,s0
  5ac78c:	0816b1bb 	j	0x5ac6ec
  5ac790:	00000000 	nop
  5ac794:	3c020075 	lui	v0,0x75
  5ac798:	8c42cf58 	lw	v0,-12456(v0)
  5ac79c:	1040ffd6 	beqz	v0,0x5ac6f8
  5ac7a0:	2402ffff 	li	v0,-1
  5ac7a4:	0c16276a 	jal	0x589da8
  5ac7a8:	00000000 	nop
  5ac7ac:	5040ffd2 	beqzl	v0,0x5ac6f8
  5ac7b0:	2402ffff 	li	v0,-1
  5ac7b4:	3c04006d 	lui	a0,0x6d
  5ac7b8:	3c05006f 	lui	a1,0x6f
  5ac7bc:	2484381c 	addiu	a0,a0,14364
  5ac7c0:	24a59dac 	addiu	a1,a1,-25172
  5ac7c4:	0c101b74 	jal	0x406dd0
  5ac7c8:	2406007d 	li	a2,125
  5ac7cc:	0816b1be 	j	0x5ac6f8
  5ac7d0:	2402ffff 	li	v0,-1
  5ac7d4:	0c16276a 	jal	0x589da8
  5ac7d8:	00000000 	nop
  5ac7dc:	1040ffc1 	beqz	v0,0x5ac6e4
  5ac7e0:	3c05006f 	lui	a1,0x6f
  5ac7e4:	3c04006f 	lui	a0,0x6f
  5ac7e8:	92470000 	lbu	a3,0(s2)
  5ac7ec:	24849cc4 	addiu	a0,a0,-25404
  5ac7f0:	24a59dac 	addiu	a1,a1,-25172
  5ac7f4:	0c101b74 	jal	0x406dd0
  5ac7f8:	24060086 	li	a2,134
  5ac7fc:	1640ffbb 	bnez	s2,0x5ac6ec
  5ac800:	2402ffff 	li	v0,-1
  5ac804:	0816b1bf 	j	0x5ac6fc
  5ac808:	8fbf003c 	lw	ra,60(sp)
  5ac80c:	0c15c5ff 	jal	0x5717fc
  5ac810:	02602021 	move	a0,s3
  5ac814:	0040a021 	move	s4,v0
  5ac818:	2c420081 	sltiu	v0,v0,129
  5ac81c:	14400029 	bnez	v0,0x5ac8c4
  5ac820:	3c020075 	lui	v0,0x75
  5ac824:	8c42cf58 	lw	v0,-12456(v0)
  5ac828:	1040ffae 	beqz	v0,0x5ac6e4
  5ac82c:	00000000 	nop
  5ac830:	0c16276a 	jal	0x589da8
  5ac834:	00000000 	nop
  5ac838:	1040ffaa 	beqz	v0,0x5ac6e4
  5ac83c:	3c05006f 	lui	a1,0x6f
  5ac840:	3c04006f 	lui	a0,0x6f
  5ac844:	24020080 	li	v0,128
  5ac848:	24849cf0 	addiu	a0,a0,-25360
  5ac84c:	24a59dac 	addiu	a1,a1,-25172
  5ac850:	afa20010 	sw	v0,16(sp)
  5ac854:	24060093 	li	a2,147
  5ac858:	0c101b74 	jal	0x406dd0
  5ac85c:	02803821 	move	a3,s4
  5ac860:	0816b1ff 	j	0x5ac7fc
  5ac864:	00000000 	nop
  5ac868:	0c15c5b0 	jal	0x5716c0
  5ac86c:	02602021 	move	a0,s3
  5ac870:	a2020001 	sb	v0,1(s0)
  5ac874:	2c420011 	sltiu	v0,v0,17
  5ac878:	54400020 	bnezl	v0,0x5ac8fc
  5ac87c:	ae50000c 	sw	s0,12(s2)
  5ac880:	3c020075 	lui	v0,0x75
  5ac884:	8c42cf58 	lw	v0,-12456(v0)
  5ac888:	1040ffbe 	beqz	v0,0x5ac784
  5ac88c:	00000000 	nop
  5ac890:	0c16276a 	jal	0x589da8
  5ac894:	00000000 	nop
  5ac898:	1040ffba 	beqz	v0,0x5ac784
  5ac89c:	3c04006d 	lui	a0,0x6d
  5ac8a0:	92070001 	lbu	a3,1(s0)
  5ac8a4:	3c05006f 	lui	a1,0x6f
  5ac8a8:	24843f34 	addiu	a0,a0,16180
  5ac8ac:	24a59dac 	addiu	a1,a1,-25172
  5ac8b0:	240600b7 	li	a2,183
  5ac8b4:	0c101b74 	jal	0x406dd0
  5ac8b8:	00000000 	nop
  5ac8bc:	0816b1e1 	j	0x5ac784
  5ac8c0:	00000000 	nop
  5ac8c4:	24110006 	li	s1,6
  5ac8c8:	24050096 	li	a1,150
  5ac8cc:	72918802 	mul	s1,s4,s1
  5ac8d0:	0c102114 	jal	0x408450
  5ac8d4:	26240004 	addiu	a0,s1,4
  5ac8d8:	1040002b 	beqz	v0,0x5ac988
  5ac8dc:	00408021 	move	s0,v0
  5ac8e0:	12800005 	beqz	s4,0x5ac8f8
  5ac8e4:	ac540000 	sw	s4,0(v0)
  5ac8e8:	24450004 	addiu	a1,v0,4
  5ac8ec:	02602021 	move	a0,s3
  5ac8f0:	0c15c702 	jal	0x571c08
  5ac8f4:	3226fffe 	andi	a2,s1,0xfffe
  5ac8f8:	ae50000c 	sw	s0,12(s2)
  5ac8fc:	aeb20010 	sw	s2,16(s5)
  5ac900:	96620006 	lhu	v0,6(s3)
  5ac904:	96a3000e 	lhu	v1,14(s5)
  5ac908:	00561023 	subu	v0,v0,s6
  5ac90c:	00431026 	xor	v0,v0,v1
  5ac910:	2403ffff 	li	v1,-1
  5ac914:	0002180a 	movz	v1,zero,v0
  5ac918:	0816b1be 	j	0x5ac6f8
  5ac91c:	00601021 	move	v0,v1
  5ac920:	3c020075 	lui	v0,0x75
  5ac924:	8c42cf58 	lw	v0,-12456(v0)
  5ac928:	1040ff6e 	beqz	v0,0x5ac6e4
  5ac92c:	00000000 	nop
  5ac930:	0c16276a 	jal	0x589da8
  5ac934:	00000000 	nop
  5ac938:	1040ff6a 	beqz	v0,0x5ac6e4
  5ac93c:	3c05006f 	lui	a1,0x6f
  5ac940:	3c04006d 	lui	a0,0x6d
  5ac944:	2484381c 	addiu	a0,a0,14364
  5ac948:	24a59dac 	addiu	a1,a1,-25172
  5ac94c:	240600a8 	li	a2,168
  5ac950:	0c101b74 	jal	0x406dd0
  5ac954:	00000000 	nop
  5ac958:	0816b1ff 	j	0x5ac7fc
  5ac95c:	00000000 	nop
  5ac960:	0c16276a 	jal	0x589da8
  5ac964:	00000000 	nop
  5ac968:	1040ff86 	beqz	v0,0x5ac784
  5ac96c:	3c04006d 	lui	a0,0x6d
  5ac970:	92070000 	lbu	a3,0(s0)
  5ac974:	3c05006f 	lui	a1,0x6f
  5ac978:	24843f08 	addiu	a0,a0,16136
  5ac97c:	24a59dac 	addiu	a1,a1,-25172
  5ac980:	0816b22d 	j	0x5ac8b4
  5ac984:	240600af 	li	a2,175
  5ac988:	3c020075 	lui	v0,0x75
  5ac98c:	8c42cf58 	lw	v0,-12456(v0)
  5ac990:	1040ff54 	beqz	v0,0x5ac6e4
  5ac994:	00000000 	nop
  5ac998:	0c16276a 	jal	0x589da8
  5ac99c:	00000000 	nop
  5ac9a0:	1040ff50 	beqz	v0,0x5ac6e4
  5ac9a4:	3c05006f 	lui	a1,0x6f
  5ac9a8:	3c04006d 	lui	a0,0x6d
  5ac9ac:	2484381c 	addiu	a0,a0,14364
  5ac9b0:	24a59dac 	addiu	a1,a1,-25172
  5ac9b4:	0816b254 	j	0x5ac950
  5ac9b8:	24060099 	li	a2,153
