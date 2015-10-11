all: ubuntu centos
ubuntu:
	cd ubuntu; sudo docker build -t ubuntu-chalktalk .

centos:
	cd centos; sudo docker build -t centos-chalktalk .

run:
	sudo docker run --name ubuntu-chalktalk-001 ubuntu-chalktalk
	sudo docker run --name centos-chalktalk-001 centos-chalktalk
clean:
	sudo docker rm -f ubuntu-chalktalk-001 centos-chalktalk-001

.PHONY: ubuntu centos
