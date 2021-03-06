default: build

ensure-out-dir:
	@mkdir -p out

build: ensure-out-dir
	@go build -o out/libpitaya_cluster.dylib -buildmode=c-shared .

build-csharp-example:
	@cd ./csharp-example && msbuild
	
build-csharp-lib:
	@cd ./csharp-lib && msbuild
	
run-csharp-example:
	@cd ./csharp-example/csharp-example && mono ./bin/Debug/csharp-example.exe

build-go-server:
	@cd ./go-server && dep ensure

run-go-server:
	@go run ./go-server/main.go

submodules:
	@git submodule update --init --recursive --remote

protos-compile: submodules
	@protoc --csharp_out=./csharp-example/csharp-example/gen/ ./go-server/protos/*.proto
	@protoc --csharp_out=./unity-example/Assets/Gen/ ./go-server/protos/*.proto
	@protoc --proto_path=pitaya-protos --csharp_out=./csharp-lib/cluster-lib/gen ./pitaya-protos/*.proto
	@protoc --proto_path=pitaya-protos --python_out=./python-lib/gen ./pitaya-protos/*.proto
	@protoc --proto_path=./go-server/protos --python_out=./python-lib/gen/ ./go-server/protos/cluster.proto
	@protoc --gogofaster_out=. ./go-server/protos/*.proto

start-deps:
	@docker-compose up -d

stop-deps:
	@docker-compose down
