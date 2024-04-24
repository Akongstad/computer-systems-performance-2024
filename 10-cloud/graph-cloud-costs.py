import matplotlib.pyplot as plt


def S3(requests, gb=2000):
    """
    :param requests: 1000s of requests.
    :param gb. storage per month
    """
    return 0.0004 * requests + 0.023 * gb


def cache(gb=2000):
    """
        Per month.
    """
    return 0.0043 * 24 * 30 + 0.10 * gb * 43_200 / (86_400 / 30)


if __name__ == '__main__':
    # Define range of requests
    requests_range = range(0, 10_000_000, 100)  # 0 to 1000 with step 100

    # Calculate costs for each range of requests
    s3_costs = [S3(requests) for requests in requests_range]
    cache_costs = [cache() for _ in requests_range]

    # Plotting
    plt.plot(requests_range, s3_costs, label='S3 Costs')
    plt.plot(requests_range, cache_costs, label='Cache Costs')
    plt.xlabel('Number of Requests (1000s)')
    plt.ylabel('Costs ($)')
    plt.title('Cost Comparison as Number of Requests Increases')
    plt.legend()
    plt.grid(True)
    plt.show()
