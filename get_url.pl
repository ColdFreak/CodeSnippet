#!/usr/bin/perl 

use strict;
use LWP;

my $url = shift;

my $agent = LWP::UserAgent->new;
my $request = HTTP::Request->new(GET => $url);

my $response = $agent->request($request);

$response->is_success or die "$url: ", $response->message,"\n";

print $response->content;


