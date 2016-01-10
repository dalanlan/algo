package main

import (
	"crypto/sha1"
	"fmt"
	"io/ioutil"
	// "os"
	// "strings"
	// "time"

	// etcdstorage "k8s.io/kubernetes/pkg/storage/etcd"

	// "github.com/coreos/go-etcd/etcd"
	// "github.com/golang/glog"
	// "github.com/spf13/pflag"
)

// sum returns in string the SHA-1 hash for the input file, error if there is any
func sum(file string) (string, error) {
	data, err := ioutil.ReadFile(file)
	if err != nil {
		return nil, err
	}
	hash := sha1.New()
	_, err = hash.Write(data)
	if err != nil {
		return nil, err
	}
	return fmt.Sprintf("%x", hash.Sum(nil)), nil
}

func main() {
	fmt.Printf(sum("flag.go"))
}
