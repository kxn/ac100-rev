; func _wserv_sqlite_thread_main @ 0x005f86fc size=0x2a4
  5f86fc:	3c02007d 	lui	v0,0x7d
  5f8700:	27bdffd0 	addiu	sp,sp,-48
  5f8704:	8c42bee0 	lw	v0,-16672(v0)
  5f8708:	afbf002c 	sw	ra,44(sp)
  5f870c:	afb40028 	sw	s4,40(sp)
  5f8710:	afb30024 	sw	s3,36(sp)
  5f8714:	afb20020 	sw	s2,32(sp)
  5f8718:	afb1001c 	sw	s1,28(sp)
  5f871c:	14400013 	bnez	v0,0x5f876c
  5f8720:	afb00018 	sw	s0,24(sp)
  5f8724:	3c100070 	lui	s0,0x70
  5f8728:	3c05007d 	lui	a1,0x7d
  5f872c:	2604831c 	addiu	a0,s0,-31972
  5f8730:	0c17de31 	jal	0x5f78c4
  5f8734:	24a5bfa8 	addiu	a1,a1,-16472
  5f8738:	10400026 	beqz	v0,0x5f87d4
  5f873c:	3c020075 	lui	v0,0x75
  5f8740:	8c42fe70 	lw	v0,-400(v0)
  5f8744:	14400015 	bnez	v0,0x5f879c
  5f8748:	8fbf002c 	lw	ra,44(sp)
  5f874c:	00001021 	move	v0,zero
  5f8750:	8fb40028 	lw	s4,40(sp)
  5f8754:	8fb30024 	lw	s3,36(sp)
  5f8758:	8fb20020 	lw	s2,32(sp)
  5f875c:	8fb1001c 	lw	s1,28(sp)
  5f8760:	8fb00018 	lw	s0,24(sp)
  5f8764:	03e00008 	jr	ra
  5f8768:	27bd0030 	addiu	sp,sp,48
  5f876c:	0c16276a 	jal	0x589da8
  5f8770:	00000000 	nop
  5f8774:	5040ffec 	beqzl	v0,0x5f8728
  5f8778:	3c100070 	lui	s0,0x70
  5f877c:	3c040070 	lui	a0,0x70
  5f8780:	3c050070 	lui	a1,0x70
  5f8784:	2484b6cc 	addiu	a0,a0,-18740
  5f8788:	24a5bb98 	addiu	a1,a1,-17512
  5f878c:	0c101b74 	jal	0x406dd0
  5f8790:	240604ac 	li	a2,1196
  5f8794:	0817e1ca 	j	0x5f8728
  5f8798:	3c100070 	lui	s0,0x70
  5f879c:	0c16276a 	jal	0x589da8
  5f87a0:	00000000 	nop
  5f87a4:	5040ffe9 	beqzl	v0,0x5f874c
  5f87a8:	8fbf002c 	lw	ra,44(sp)
  5f87ac:	3c040070 	lui	a0,0x70
  5f87b0:	3c050070 	lui	a1,0x70
  5f87b4:	2484b70c 	addiu	a0,a0,-18676
  5f87b8:	24a5bb98 	addiu	a1,a1,-17512
  5f87bc:	240604b2 	li	a2,1202
  5f87c0:	2607831c 	addiu	a3,s0,-31972
  5f87c4:	0c101b74 	jal	0x406dd0
  5f87c8:	00000000 	nop
  5f87cc:	0817e1d3 	j	0x5f874c
  5f87d0:	8fbf002c 	lw	ra,44(sp)
  5f87d4:	3c100070 	lui	s0,0x70
  5f87d8:	3c05007d 	lui	a1,0x7d
  5f87dc:	260482f0 	addiu	a0,s0,-32016
  5f87e0:	0c17de31 	jal	0x5f78c4
  5f87e4:	24a5bfac 	addiu	a1,a1,-16468
  5f87e8:	1040000f 	beqz	v0,0x5f8828
  5f87ec:	3c020075 	lui	v0,0x75
  5f87f0:	8c42fe70 	lw	v0,-400(v0)
  5f87f4:	1040ffd5 	beqz	v0,0x5f874c
  5f87f8:	8fbf002c 	lw	ra,44(sp)
  5f87fc:	0c16276a 	jal	0x589da8
  5f8800:	00000000 	nop
  5f8804:	5040ffd1 	beqzl	v0,0x5f874c
  5f8808:	8fbf002c 	lw	ra,44(sp)
  5f880c:	3c040070 	lui	a0,0x70
  5f8810:	3c050070 	lui	a1,0x70
  5f8814:	2484b70c 	addiu	a0,a0,-18676
  5f8818:	24a5bb98 	addiu	a1,a1,-17512
  5f881c:	240604b9 	li	a2,1209
  5f8820:	0817e1f1 	j	0x5f87c4
  5f8824:	260782f0 	addiu	a3,s0,-32016
  5f8828:	3c100070 	lui	s0,0x70
  5f882c:	3c05007d 	lui	a1,0x7d
  5f8830:	26048340 	addiu	a0,s0,-31936
  5f8834:	0c17de31 	jal	0x5f78c4
  5f8838:	24a5bfb0 	addiu	a1,a1,-16464
  5f883c:	10400010 	beqz	v0,0x5f8880
  5f8840:	3c13007d 	lui	s3,0x7d
  5f8844:	3c020075 	lui	v0,0x75
  5f8848:	8c42fe70 	lw	v0,-400(v0)
  5f884c:	1040ffbf 	beqz	v0,0x5f874c
  5f8850:	8fbf002c 	lw	ra,44(sp)
  5f8854:	0c16276a 	jal	0x589da8
  5f8858:	00000000 	nop
  5f885c:	5040ffbb 	beqzl	v0,0x5f874c
  5f8860:	8fbf002c 	lw	ra,44(sp)
  5f8864:	3c040070 	lui	a0,0x70
  5f8868:	3c050070 	lui	a1,0x70
  5f886c:	2484b70c 	addiu	a0,a0,-18676
  5f8870:	24a5bb98 	addiu	a1,a1,-17512
  5f8874:	240604c0 	li	a2,1216
  5f8878:	0817e1f1 	j	0x5f87c4
  5f887c:	26078340 	addiu	a3,s0,-31936
  5f8880:	3c140070 	lui	s4,0x70
  5f8884:	3c12007d 	lui	s2,0x7d
  5f8888:	2673bf8c 	addiu	s3,s3,-16500
  5f888c:	2694ba70 	addiu	s4,s4,-17808
  5f8890:	2642bf88 	addiu	v0,s2,-16504
  5f8894:	2405ffff 	li	a1,-1
  5f8898:	3c11007d 	lui	s1,0x7d
  5f889c:	0c1020b4 	jal	0x4082d0
  5f88a0:	8c440010 	lw	a0,16(v0)
  5f88a4:	0817e230 	j	0x5f88c0
  5f88a8:	00000000 	nop
  5f88ac:	2622bf88 	addiu	v0,s1,-16504
  5f88b0:	2406ffff 	li	a2,-1
  5f88b4:	8c440014 	lw	a0,20(v0)
  5f88b8:	0c1021b0 	jal	0x4086c0
  5f88bc:	8c450010 	lw	a1,16(v0)
  5f88c0:	0c10206c 	jal	0x4081b0
  5f88c4:	02602021 	move	a0,s3
  5f88c8:	1040fff8 	beqz	v0,0x5f88ac
  5f88cc:	00408021 	move	s0,v0
  5f88d0:	2631bf88 	addiu	s1,s1,-16504
  5f88d4:	0c102140 	jal	0x408500
  5f88d8:	00402021 	move	a0,v0
  5f88dc:	0c101fcc 	jal	0x407f30
  5f88e0:	8e240010 	lw	a0,16(s1)
  5f88e4:	8e040010 	lw	a0,16(s0)
  5f88e8:	1080000c 	beqz	a0,0x5f891c
  5f88ec:	00000000 	nop
  5f88f0:	8e02000c 	lw	v0,12(s0)
  5f88f4:	2c430007 	sltiu	v1,v0,7
  5f88f8:	10600008 	beqz	v1,0x5f891c
  5f88fc:	00021080 	sll	v0,v0,0x2
  5f8900:	02821021 	addu	v0,s4,v0
  5f8904:	8c420000 	lw	v0,0(v0)
  5f8908:	00400008 	jr	v0
  5f890c:	00000000 	nop
  5f8910:	0c17da3f 	jal	0x5f68fc
  5f8914:	00000000 	nop
  5f8918:	8e040010 	lw	a0,16(s0)
  5f891c:	10800004 	beqz	a0,0x5f8930
  5f8920:	00000000 	nop
  5f8924:	0c101f7c 	jal	0x407df0
  5f8928:	00000000 	nop
  5f892c:	ae000010 	sw	zero,16(s0)
  5f8930:	0c101f7c 	jal	0x407df0
  5f8934:	02002021 	move	a0,s0
  5f8938:	0817e225 	j	0x5f8894
  5f893c:	2642bf88 	addiu	v0,s2,-16504
  5f8940:	0c17dfcf 	jal	0x5f7f3c
  5f8944:	00000000 	nop
  5f8948:	0817e246 	j	0x5f8918
  5f894c:	00000000 	nop
  5f8950:	0c17da0d 	jal	0x5f6834
  5f8954:	00000000 	nop
  5f8958:	0817e246 	j	0x5f8918
  5f895c:	00000000 	nop
  5f8960:	0c17d98a 	jal	0x5f6628
  5f8964:	00000000 	nop
  5f8968:	0817e246 	j	0x5f8918
  5f896c:	00000000 	nop
  5f8970:	0c17dfa1 	jal	0x5f7e84
  5f8974:	8c840000 	lw	a0,0(a0)
  5f8978:	0817e246 	j	0x5f8918
  5f897c:	00000000 	nop
  5f8980:	0c17d9d7 	jal	0x5f675c
  5f8984:	00000000 	nop
  5f8988:	0817e246 	j	0x5f8918
  5f898c:	00000000 	nop
  5f8990:	0c17df73 	jal	0x5f7dcc
  5f8994:	8c840000 	lw	a0,0(a0)
  5f8998:	0817e246 	j	0x5f8918
  5f899c:	00000000 	nop
