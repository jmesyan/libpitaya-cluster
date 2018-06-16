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
	@cd ./csharp-example && mono ./bin/Debug/net35/example.exe

run-go-server:
	@cd ./go-server && go run main.go

protos-compile:
	@protoc --csharp_out=./csharp-example/gen/ ./go-server/protos/*.proto
	@protoc --csharp_out=./unity-example/Assets/Gen/ ./go-server/protos/*.proto
	@protoc --gogofaster_out=. ./go-server/protos/*.proto

start-deps:
	@docker-compose up -d

stop-deps:
	@docker-compose down
